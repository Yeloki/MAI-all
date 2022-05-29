//
// Created by Yeloki on 30.05.2022.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list *list_create() {


    list *lst = (list *) malloc(sizeof(list));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}

void list_insert(list *lst, item val) {
    list_node *node = (list_node *) malloc(sizeof(list_node));
    node->next = NULL;
    node->prev = lst->tail;
    node->data = val;
    if (lst->tail != NULL) {
        lst->tail->next = node;
    }
    lst->tail = node;
    if (lst->head == NULL) {
        lst->head = node;
    }
}

void list_fprint(list *lst, FILE *stream) {
    fprintf(stream, "Your list\n");
    list_node *node = lst->head;
    while (node != NULL) {
        fprintf(stream, "[%lf]->", node->data);
        node = node->next;
    }
    printf("\n");
}

list_node *get_by_id_list(list *lst, int id, int size) {
    list_node *node = NULL;
    int pos;
    if (id < size / 2) {
        pos = 0;
        node = lst->head;
        while (node != NULL && pos < id) {
            node = node->next;
            pos++;
        }
    } else {
        pos = size - 1;
        node = lst->tail;
        while (node != NULL && pos > id) {
            node = node->prev;
            pos--;
        }

    }
    return node;
}

void delete_elem(list *lst, int id, int size) {
    list_node *node = get_by_id_list(lst, id, size);
    if (node == NULL) {
        printf("Error\n");
        return;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    if (node->prev == NULL) {
        lst->head = node->next;
    }
    if (node->next == NULL) {
        lst->tail = node->prev;
    }
    free(node);
}

