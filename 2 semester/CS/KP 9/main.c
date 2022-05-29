#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int main(int argc, char *argv[]) {
    FILE *file;
    char name[50];
    if (argc > 1) {
        file = fopen(argv[1], "r");
    } else {
        printf("Enter the file's name: ");
        scanf("%s", name);
        file = fopen(name, "r");
    }
    line table[12];
    double keys[12];
    int n = 0, key;
    while (fscanf(file, "%lf", &keys[n]) > 0) {
        fgets(table[n].data, 100, file);
        n++;
    }
    printf("Your table:\n");
    for (int i = 0; i < n; i++) {
        printf("%8.3lf %s", keys[i], table[i].data);
    }
    selection_sort_with_exchanges(keys, n, table);
    printf("\nSorted:\n");
    for (int i = 0; i < n; i++) {
        printf("%8.3lf %s", keys[i], table[i].data);
    }
    printf("\nType key to print (or ivalid key to exit): ");

    double key_to_find;
    while (scanf("%lf", &key_to_find) > 0) {
        if (!exists(keys, key_to_find, n)) {
            break;
        }
        int id = binary_search(keys, key_to_find, 0, n);
        printf("%8.3lf %s", keys[id], table[id].data);
        printf("Type key to print (or ivalid key to exit): ");
    }
    printf("Found invalid key\n");
    return 0;
}
