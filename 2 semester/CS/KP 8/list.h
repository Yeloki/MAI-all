//
// Created by Yeloki on 30.05.2022.
//

#ifndef KP_8_LIST_H
#define KP_8_LIST_H

#include <stdio.h>

typedef double item;
typedef struct list_node list_node;
typedef struct list list;

struct list_node {
    item data;
    list_node *next;
    list_node *prev;
};

struct list {

    list_node *head;
    list_node *tail;
};

list *list_create();

void list_insert(list *lst, item val);

void list_fprint(list *lst, FILE *stream);

list_node *get_by_id_list(list *lst, int id, int size);

void delete_elem(list *lst, int id, int size);

#endif //KP_8_LIST_H
