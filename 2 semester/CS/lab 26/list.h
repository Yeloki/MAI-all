#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct list list;
typedef struct list_el list_el;

struct list_el {
    int val;
    list_el* next;
};

struct list {
    list_el* first;
    list_el* last;
    int size;
};


void l_init(list *l);
void l_destroy(list *l);
void l_print(list *l);
bool l_push_front(list *l, int val);
int l_pop_front(list *l);
bool l_push_back(list *l, int val);
int l_pop_back(list *l);
bool is_empty(list *l);

#endif
