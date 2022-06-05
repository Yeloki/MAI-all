#include "queue.h"

void q_init(queue *q)
{
    q->head = NULL;
    q->last = NULL;
}

void q_destroy(queue *q)
{
    while (!q_is_empty(q))
        q_pop(q);
}

bool q_is_empty(queue *q)
{
    return q->head == NULL;
}

bool q_push(queue *q, token val)
{
    queue_el *element = malloc(sizeof(queue_el));
    if (element == NULL)
        return false;
    element->next = NULL;
    element->val = val;
    if (q->head == NULL)
    {
        q->head = element;
    }
    else
    {
        q->last->next = element;
    }
    q->last = element;
    return true;
}

token q_pop(queue* q)
{
    queue_el *e = q->head;
    token tmp_val = e->val;
    q->head = e->next;
    free(e);
    if (q->head == NULL)
        q->last = NULL;
    return tmp_val;
}

void q_print(queue *q)
{
    queue_el *el = q->head;
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

