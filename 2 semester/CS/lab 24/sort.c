#include "sort.h"

read_token_res read_token(token *tok, token_type prev_type)
{
    int c = getchar();
    if (c == EOF)
    {
        tok->type = TOK_NONE;
        return RTR_EOF;
    }
    if(c == '_' || ('a' <= c  && c <= 'z') ||  ('A' <= c  && c <= 'Z'))
    {
        tok->type = TOK_VAR;
        ungetc(c, stdin);
        char varname[32];
        scanf("%[_A-Za-z0-9]", varname);
        strcpy(tok->varname, varname);
        return RTR_OK;
    }
    else if ('0' <= c && c <= '9')
    {
        tok->type = TOK_CONST;
        ungetc(c, stdin);
        double cval;
        scanf("%lf", &cval);
        tok->constval = cval;
        return RTR_OK;
    }
    else if (c == '-')
    {
        tok->type = TOK_OP;
        if (prev_type == TOK_OP || prev_type == TOK_LBR || prev_type == TOK_NONE)
            tok->op = '~';
        else
            tok->op = c;
        return RTR_OK;
    }
    else if (!isspace(c))
    {
        if (c == '(')
        {
            tok->type = TOK_LBR;
            tok->op = c;
            return RTR_OK;
        }
        else if (c == ')')
        {
            tok->type = TOK_RBR;
            tok->op = c;
            return RTR_OK;
        }
        else if (c == '+' || c == '*' || c == '/' || c == '^')
        {
            tok->type = TOK_OP;
            tok->op = c;
            return RTR_OK;
        }
        else
            return RTR_ERR;
    }
    else
    {
        tok->type = TOK_NONE;
        if (c == '\n')
            return RTR_EOE;
        else
            return RTR_OK;
    }
}

read_exp_res read_expression(queue *q)
{
    printf("Enter expression:\n");
    token tok;
    token_type prev_type = TOK_NONE;
    read_token_res rtr;
    while ((rtr = read_token(&tok, prev_type)) == RTR_OK)
    {
        if(tok.type == TOK_NONE)
            continue;
        prev_type = tok.type;
        q_push(q, tok);
    }
    switch (rtr)
    {
        case RTR_ERR: return RER_ERR;
        case RTR_EOE: return RER_OK;
        case RTR_EOF: return RER_EOF;
        default: return RER_ERR;
    }
}

bool should_pop_out(char new_op, char stack_op)
{
    if (new_op == '~' || new_op == '^')
    {
        if (new_op == '^' && stack_op == '~')
            return true;
        return false;
    }
    else
    {
        if (new_op == '+' || new_op == '-')
            return true;
        else
        {
            if (stack_op != '+' && stack_op != '-')
                return true;
            return false;
        }
    }
}

ss_result sorting_station(queue *src, queue *dest)
{
    stack_token s;
    s_init_token(&s);
    while (!q_is_empty(src))
    {
        token t = q_pop(src);
        if (t.type == TOK_VAR || t.type == TOK_CONST)
            q_push(dest, t);
        else if (t.type == TOK_LBR)
            s_push_token(&s, t);
        else if (t.type == TOK_RBR)
        {
            token curr;
            curr.type = TOK_NONE;
            while (!s_is_empty_token(&s) && (curr = s_pop_token(&s)).type != TOK_LBR)
            {
                q_push(dest, curr);
            }
            if (curr.type != TOK_LBR)
            {
                s_destroy_token(&s);
                return SSR_BR_ERR;
            }
        }
        else
        {
            token curr;
            curr.type = TOK_NONE;
            while (!s_is_empty_token(&s))
            {
                if ((curr = s_pop_token(&s)).type == TOK_OP && should_pop_out(t.op, curr.op))
                    q_push(dest, curr);
                else
                {
                    s_push_token(&s, curr);
                    break;
                }
            }
            s_push_token(&s, t);
        }
    }
    while (!s_is_empty_token(&s))
    {
        token curr = s_pop_token(&s);
        if (curr.type == TOK_LBR)
        {
            s_destroy_token(&s);
            return SSR_BR_ERR;
        }
        q_push(dest, curr);
    }
    s_destroy_token(&s);
    return SSR_OK;
}

build_tree_res build_tree_dijk(queue *polish, treeptr *tree)
{
    if (q_is_empty(polish))
    {
        *tree = NULL;
        return BTR_OK;
    }
    stack_treeptr s;
    s_init_treeptr(&s);

    while (!q_is_empty(polish))
    {
        token t = q_pop(polish);
        treeptr l , r;
        if (t.type == TOK_VAR || t.type == TOK_CONST)
        {
            l = NULL;
            r = NULL;
        }
        else if (t.op == '~')
        {
            l = NULL;
            if (s_is_empty_treeptr(&s))
            {
                s_destroy_treeptr(&s);
                return BTR_ERR;
            }
            r = s_pop_treeptr(&s);
        }
        else
        {
            if (s_is_empty_treeptr(&s))
            {
                s_destroy_treeptr(&s);
                return BTR_ERR;
            }
            r = s_pop_treeptr(&s);
            if (s_is_empty_treeptr(&s))
            {
                s_destroy_treeptr(&s);
                return BTR_ERR;
            }
            l = s_pop_treeptr(&s);
        }
        treeptr new_e = malloc(sizeof(struct tree));
        if (new_e == NULL)
            return BTR_ERR;
        new_e->val = t;
        new_e->l = l;
        new_e->r = r;
        s_push_treeptr(&s, new_e);
    }
    treeptr res = s_pop_treeptr(&s);
    if (!s_is_empty_treeptr(&s))
    {
        t_delete(&res);
        while (!s_is_empty_treeptr(&s))
        {
            treeptr to_del = s_pop_treeptr(&s);
            node_delete(&to_del);
        }
        s_destroy_treeptr(&s);
        return BTR_ERR;
    }
    else
    {
        *tree = res;
        s_destroy_treeptr(&s);
        return BTR_OK;
    }
    return BTR_OK;
}


read_token_res read_token_char(token *tok, token_type prev_type, char c, char* a, char* b)
{
    if (c == EOF)
    {
        tok->type = TOK_NONE;
        return RTR_EOF;
    }
    if(c == 'a')
    {
        tok->type = TOK_VAR;
        strcpy(tok->varname, a);
        return RTR_OK;
    } else if(c == 'b')
    {
        tok->type = TOK_VAR;
        strcpy(tok->varname, b);
        return RTR_OK;
    }
    else if (c == '2')
    {
        tok->type = TOK_CONST;
        tok->constval = 2;
        return RTR_OK;
    }
    else if (c == '-')
    {
        tok->type = TOK_OP;
            tok->op = c;
        return RTR_OK;
    }
    else 
        if (c == '(')
        {
            tok->type = TOK_LBR;
            tok->op = c;
            return RTR_OK;
        }
        else if (c == ')')
        {
            tok->type = TOK_RBR;
            tok->op = c;
            return RTR_OK;
        }
        else if (c == '+' || c == '*' || c == '/' || c == '^')
        {
            tok->type = TOK_OP;
            tok->op = c;
            return RTR_OK;
        }
        else
            return RTR_ERR;

        tok->type = TOK_NONE;
        if (c == '\n')
            return RTR_EOE;
        else
            return RTR_OK;

}
