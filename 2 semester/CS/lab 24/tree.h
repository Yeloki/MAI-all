#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

bool insert_before(treeptr *pos, token val);
void node_delete(treeptr *pos);
void print_tree(treeptr t, int level);
void infix_form_print(treeptr t, token p, bool is_start);
void t_delete(treeptr *t);

#endif

