#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void s_init_token(stack_token *s)
{
    s->head = NULL;
}
void s_init_treeptr(stack_treeptr *s)
{
    s->head = NULL;
}

void s_destroy_token(stack_token *s)
{
    while (!s_is_empty_token(s))
        s_pop_token(s);
}
void s_destroy_treeptr(stack_treeptr *s)
{
    while (!s_is_empty_treeptr(s))
        s_pop_treeptr(s);
}

bool s_is_empty_token(stack_token *s)
{
    return s->head == NULL;
}
bool s_is_empty_treeptr(stack_treeptr *s)
{
    return s->head == NULL;
}

bool s_push_token(stack_token *s, token val)
{
    stack_el_token *element = malloc(sizeof(stack_el_token));
    if (element == NULL)
        return false;
    element->next = s->head;
    element->val = val;
    s->head = element;
    return true;
}
bool s_push_treeptr(stack_treeptr *s, treeptr val)
{
    stack_el_treeptr *element = malloc(sizeof(stack_el_treeptr));
    if (element == NULL)
        return false;
    element->next = s->head;
    element->val = val;
    s->head = element;
    return true;
}

token s_pop_token(stack_token *s)
{
    stack_el_token *e = s->head;
    token tmp_val = e->val;
    s->head = e->next;
    free(e);
    return tmp_val;
}

treeptr s_pop_treeptr(stack_treeptr *s)
{
    stack_el_treeptr *e = s->head;
    treeptr tmp_val = e->val;
    s->head = e->next;
    free(e);
    return tmp_val;
}

void s_print(stack_token *q)
{
    stack_el_token *el = q->head;
    if (el == NULL)
        return;
    while (el != NULL)
    {
        if (el->val.type == TOK_CONST)
            printf("%d ", el->val.constval);
        else if (el->val.type == TOK_OP)
            printf("%c ", el->val.op);
        else
            printf("%s ", el->val.varname);
        el = el->next;
    }
    printf("\n");
}
