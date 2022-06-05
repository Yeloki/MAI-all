#include "tree.h"

bool insert_before(treeptr *pos, token val)
{
    if (*pos != NULL)
        return false;
    treeptr new_node = malloc(sizeof(tree));
    if (new_node == NULL)
        return false;
    new_node->val = val;
    new_node->l = NULL;
    new_node->r = NULL;
    *pos = new_node;
    return true;
}

void node_delete(treeptr* pos)
{
    if (*pos == NULL)
        return;
    treeptr tofree = *pos;
    treeptr l = (*pos)->l;
    treeptr r = (*pos)->r;

    if (r == NULL)
        *pos = l;
    else if(l == NULL)
        *pos = r;
    else
        *pos = l;
    free(tofree);
}

void print_tree(treeptr t, int level)
{
    if (t == NULL)
        return;
    print_tree(t->l, level + 1);
    for (int i = 0; i < level; ++i)
        printf("\t");
    if (t->val.type == TOK_CONST)
        printf("%d\n", t->val.constval);
    else if (t->val.type == TOK_OP)
        printf("%c\n", t->val.op);
    else
        printf("%s\n", t->val.varname);
    print_tree(t->r, level + 1);
}

void infix_form_print(treeptr t, token p, bool is_start)
{
    if (t == NULL)
        return;
    if (t->val.type == TOK_OP && !is_start)
    {
        if (p.type == TOK_OP)
        {
            if ((p.op == '*' || p.op == '/') && (t->val.op  == '+' || t->val.op == '-'))
                printf("(");
            else if (p.op == '^' && t->val.op != '~')
                printf("(");
            else if (p.op == '~')
                printf("(");
        }
    }
    infix_form_print(t->l, t->val, false);
    if (t->val.type == TOK_CONST)
        printf("%d", t->val.constval);
    else if (t->val.type == TOK_OP)
    {
        if (t->val.op != '~')
            printf(" %c ", t->val.op);
        else
            printf(" - ");
    }
    else
        printf("%s", t->val.varname);
    infix_form_print(t->r, t->val, false);
    if (t->val.type == TOK_OP && !is_start)
    {
        if (p.type == TOK_OP)
        {
            if ((p.op == '*' || p.op == '/') && (t->val.op  == '+' || t->val.op == '-'))
                printf(")");
            else if (p.op == '^' && t->val.op != '~')
                printf(")");
            else if (p.op == '~')
                printf(")");
        }
    }
}

void t_delete(treeptr *t)
{
    while (*t != NULL)
        node_delete(t);
}

