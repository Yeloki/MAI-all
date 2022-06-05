// вариант 63

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "sort.h"


int memorize_var_tree(treeptr t, char* a, char* b)
{
	if (t == NULL)
        return -1;
    if (t->val.type == TOK_OP && t->val.op == '-') {
		
		if (t->r->val.op == '^' && t->r->val.type == TOK_OP) {
			if (t->r->r->val.type == TOK_CONST && t->r->r->val.constval == 3) {
				if (t->r->l->val.type == TOK_VAR) {
					strcpy(b, t->r->l->val.varname);
				}	else {
					printf("\nError: wrong variable 2\n");
					return -1;
				}
			} else { 
				printf("\nError: wrong degree\n");
				return -1;
			} 
		}else {
			 printf("\nError: wrong form\n");
			 return -1;
			}

		if (t->l->val.op == '^' && t->l->val.type == TOK_OP) {
			if (t->l->r->val.type == TOK_CONST && t->l->r->val.constval == 3) {
				if (t->l->l->val.type == TOK_VAR) {
					strcpy(a, t->l->l->val.varname);
				} else {
					printf("\nError: wrong variable 1\n");
					return -1;
				}
			} else { 
				printf("\nError: wrong degree\n");
				return -1;
			}
		} else {
			 printf("\nError: wrong form\n");
			 return -1;
			}
	} else {
			printf("\nError: wrong sign. Needed '-'\n");
			return -1;
	}
	return 0;
}

int main()
{
    queue input;
    q_init(&input);
    read_exp_res rer;
	char a[32];
	char b[32];
    while ((rer = read_expression(&input)) != RER_EOF)
    {
		strcpy(a, "");
		strcpy(b, "");
        if (rer == RER_ERR)
        {
            printf("Error of reading expression\n\n");
            while(!q_is_empty(&input))
                q_pop(&input);
            char to_del;
            while ((to_del = getchar()) != EOF)
            {
                if (to_del == '\n')
                    break;
            }
            continue;
        }
        queue polish;
        q_init(&polish);
        ss_result ssr = sorting_station(&input, &polish);
        if (ssr == SSR_BR_ERR)
        {
            printf("Wrong number of brackets\n\n");
            continue;
        }
        treeptr root = NULL;
        printf("\nPolish:\n");
        q_print(&polish);
        build_tree_res btr = build_tree_dijk(&polish, &root);
        if (btr == BTR_ERR)
        {
            printf("Wrong expression, can't build a tree\n\n");
            continue;
        }
        q_destroy(&polish);
		
		

        printf("\nTree:\n");
        print_tree(root, 0);
        printf("\nInfix:\n");
        if (root)
			infix_form_print(root, root->val, true);
	  
	  	if (memorize_var_tree(root, a, b) != 0) {
			continue;
		}
		queue task;
		q_init(&task);
		 token tok;
		token_type prev_type = TOK_NONE;
		char to_func[]="(a-b)*(a^2+a*b+b^2)";
		for ( int i = 0; to_func[i] != '\0'; i++ )
		{
			if ((read_token_char(&tok, prev_type, to_func[i], a, b)) == RTR_OK)
			{
				if(tok.type == TOK_NONE)
					continue;
				prev_type = tok.type;
				q_push(&task, tok);
			}
		}
	  
        printf("\n\n--------------------------------------------------------------------\n");
        printf("Task:");
        printf("\n--------------------------------------------------------------------\n");
		ssr = sorting_station(&task, &polish);
        if (ssr == SSR_BR_ERR)
        {
            printf("Wrong number of brackets\n\n");
            continue;
        }
        t_delete(&root);
        btr = build_tree_dijk(&polish, &root);
        if (btr == BTR_ERR)
        {
            printf("Wrong expression, can't build a tree\n\n");
            continue;
        }
        q_destroy(&polish);
		printf("\n--------------------------------------------------------------------\n");
        print_tree(root, 0);
        printf("\n--------------------------------------------------------------------\n");
        if (root)
            infix_form_print(root, root->val, true);
        printf("\n--------------------------------------------------------------------\n");
        printf("\n\n");
   
		t_delete(&root);
    }
    q_destroy(&input);
    return 0;
}
