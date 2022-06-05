#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

typedef struct stack_token stack_token;
typedef struct stack_treeptr stack_treeptr;
typedef struct stack_el_token stack_el_token;
typedef struct stack_el_treeptr stack_el_treeptr;

struct stack_token {
    stack_el_token *head;
};
struct stack_treeptr {
    stack_el_treeptr *head;
};

struct stack_el_token {
    token val;
    stack_el_token *next;
};
struct stack_el_treeptr {
    treeptr val;
    stack_el_treeptr *next;
};

void s_init_token(stack_token *s);
void s_init_treeptr(stack_treeptr *s);
void s_destroy_token(stack_token *s);
void s_destroy_treeptr(stack_treeptr *s);
bool s_is_empty_token(stack_token *s);
bool s_is_empty_treeptr(stack_treeptr *s);
bool s_push_token(stack_token *s, token val);
bool s_push_treeptr(stack_treeptr *s, treeptr val);
token s_pop_token(stack_token *s);
treeptr s_pop_treeptr(stack_treeptr *s);
void s_print(stack_token *q);

#endif
