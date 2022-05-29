//
// Created by Yeloki on 30.05.2022.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void create_vector(vector *v) {
    v->size = 0;
    v->num_el = 0;
    v->elem = (int *) (malloc(sizeof(int) * v->size));
}

int empty_vector(vector *v) {
    return (v->num_el == 0) ? 1 : 0;
}

int size(vector *v) {
    return (v->size);
}

void resize(vector *v) {
    v->size++;
    v->elem = (int *) (realloc(v->elem, sizeof(int) * v->size));
}

void push_back(vector *v, int value) {
    if (v->size == v->num_el) {
        resize(v);
    }

    v->elem[v->num_el] = value;
    v->num_el++;
}

void print_vector(vector *v) {
    if (empty_vector(v)) {
        printf("Вектор пуст.");
    } else {
        for (int i = 0; i < v->num_el; i++) {
            printf("%d ", v->elem[i]);
        }
        printf("\n");
    }
}

void load_matrix(vector *string, vector *column, vector *value) {
    char name[20];
    printf("введите название файла: ");
    scanf("%s", name);

    FILE *f;

    if ((f = fopen(name, "r")) == NULL) {
        printf("Ошибка, не удается открыть файл!");
        exit(1);
    }

    int num_string, num_column, val, count = 0;

    fscanf(f, "%d%d", &num_string, &num_column);
    if (num_string != num_column) {
        printf("Матрица должна быть размера n*n, иначе операция невозможна!\n");
        return;
    }
    for (int i = 0; i < num_string; i++) {
        push_back(string, count);
        for (int j = 0; j < num_column; j++) {
            fscanf(f, "%d", &val);
            if (val != 0) {
                push_back(column, j + 1);
                push_back(value, val);
                count++;
            }
        }
    }
}

void create_unit_matrix(vector *string_u, vector *column_u, vector *value_u,
                        vector *string) {
    for (int i = 0; i < string->num_el; i++) {
        push_back(string_u, i);
        push_back(column_u, i + 1);

        push_back(value_u, 1);
    }
}

void matrix_mult(vector *value, int c) {
    for (int i = 0; i < value->num_el; i++) {
        value->elem[i] *= c;
    }
}

void print_matrix(vector *string, vector *column, vector *value) {
    int col_i = 0;
    int str_i = 1;
    for (int i = 0; i < string->num_el; i++) {
        for (int j = 1; j <= string->num_el; j++) {
            if (column->elem[col_i] == j) {
                printf("%d ", value->elem[col_i]);
                col_i++;
            } else {
                printf("0 ");
            }
            if (str_i < string->num_el) {
                if (string->elem[str_i] == col_i) {
                    str_i++;
                    for (int k = 0; k < (string->num_el - j); k++) {
                        printf("0 ");
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }
    printf("\n\n");
}

void sum(vector *string_u, vector *column_u, vector *value_u, vector *string, vector *column, vector *value) {
    int m[100][100];
    int col_i = 0;
    int str_i = 1;
    for (int i = 0; i < string->num_el; i++) {
        for (int j = 1; j <= string->num_el; j++) {
            if (column->elem[col_i] == j) {
                m[i][j - 1] = value->elem[col_i];
                col_i++;
            } else {
                m[i][j - 1] = 0;
            }
            if (str_i < string->num_el) {
                if (string->elem[str_i] == col_i) {
                    str_i++;
                    for (int k = 0; k < (string->num_el - j); k++) {
                        m[i][j] = 0;
                        j++;
                    }
                    break;
                }
            }
        }
    }


    for (int i = 0; i < value_u->num_el; i++) {
        m[i][i] += value_u->elem[i];
    }

    for (int i = 0; i < string->num_el; i++) {
        for (int j = 0; j < string->num_el; j++) {
            printf("%d ", m[i][j]);

        }
        printf("\n");
    }

}

