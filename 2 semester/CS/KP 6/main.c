#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Please, enter flag\n");
        help();
        exit(1);
    } else if (!strcmp(argv[1], "-c")) {
        create_new();
    } else if (!strcmp(argv[1], "-a")) {
        add();
    } else if (!strcmp(argv[1], "-p")) {
        print();
    } else if (!strcmp(argv[1], "-r")) {
        delite();
    } else if (!strcmp(argv[1], "-f")) {
        func();
    } else if (!strcmp(argv[1], "-h")) {
        help();
    } else {
        help();
    }
    return 0;
}
