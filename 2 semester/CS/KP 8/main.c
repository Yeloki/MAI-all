#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "iterator.h"
#include <string.h>

int main(void) {
    char arg[30];
    list *lst = list_create();
    iterator *it = iterator_create(lst);
    printf("Enter 'add_to_back' to insert element in the end of list\n");
    printf("Enter 'exit' to finish program\n");
    printf("Enter 'func' to change second and one before last elements\n");
    printf("Enter 'length' to show number of elemtnts\n");
    printf("Enter 'del' to delete one element\n");
    printf("Enter 'print' to show the list\n");
    while (strcmp(arg, "exit") != 0) {
        scanf("%s", arg);
        if (strcmp(arg, "add_to_back") == 0 || strcmp(arg, "add") == 0) {
            printf("Enter number of list's elements\n");
            int i;
            double g;
            scanf("%d", &i);
            for (int j = 0; j < i; j++) {

                printf("Enter value\n");
                scanf("%lf", &g);
                list_insert(lst, g);
            }
        } else if (strcmp(arg, "func") == 0) {
            change_places(lst);
        } else if (strcmp(arg, "length") == 0) {
            printf("%d\n", iterator_length(lst));
        } else if (strcmp(arg, "del") == 0) {
            int id;
            printf("Enter id of node, beginning from 1\n");
            scanf("%d", &id);
            int size = iterator_length(lst);
            if (id > size || id <= 0) {
                printf("There is no such node\n");
            } else {
                id--;
                delete_elem(lst, id, size);
            }
        } else if (strcmp(arg, "print") == 0) {
            if (iterator_length(lst) == 0) {
                printf("List is empty\n");
            } else {
                list_fprint(lst, stdout);
            }
        } else if (strcmp(arg, "exit") == 0) {
            return 0;
        } else {
            printf("There is no such a command\n");
        }
    }
    return 0;
}

