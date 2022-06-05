#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef enum token_type token_type;
typedef struct token token;
typedef enum read_token_res read_token_res;
typedef enum read_exp_res read_exp_res;
typedef enum ss_result ss_result;
typedef enum build_tree_res build_tree_res;
typedef struct queue queue;
typedef struct queue_el queue_el;
typedef struct tree tree;
typedef struct tree* treeptr;

enum ss_result {
    SSR_OK,
    SSR_BR_ERR
};

enum read_exp_res {
    RER_OK = 0,
    RER_ERR = -2,
    RER_EOF = -1
};

enum read_token_res {
    RTR_OK,
    RTR_ERR = -3,
    RTR_EOE = -2,
    RTR_EOF = -1
};

enum token_type {
    TOK_NONE,
    TOK_CONST,
    TOK_VAR,
    TOK_OP,
    TOK_LBR,
    TOK_RBR
};

struct token {
    token_type type;
    char varname[32];
    int constval;
    char op;
};

enum build_tree_res {
    BTR_OK,
    BTR_ERR
};

struct queue_el {
    token val;
    queue_el* next;
};

struct queue {
    queue_el* head;
    queue_el* last;
};

struct tree {
    treeptr l;
    treeptr r;
    token val;
};


void q_init(queue *q);
void q_destroy(queue *q);
bool q_is_empty(queue *q);
bool q_push(queue *q, token val);
void q_print(queue *q);
token q_pop(queue *q);

#endif

