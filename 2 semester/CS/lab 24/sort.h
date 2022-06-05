#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "stack.h"

read_token_res read_token(token *tok, token_type prev_type);
read_exp_res read_expression(queue *q);
bool should_pop_out(char new_op, char stack_op);
ss_result sorting_station(queue *src, queue *dest);
build_tree_res build_tree_dijk(queue *polish,treeptr *tree);
read_token_res read_token_char(token *tok, token_type prev_type, char c, char* a, char* b);
#endif

