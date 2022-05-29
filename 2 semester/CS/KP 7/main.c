#include <stdio.h>

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    vector string, column, value, string_u, column_u, value_u;
    int a, b;

    create_vector(&string);
    create_vector(&column);
    create_vector(&value);
    load_matrix(&string, &column, &value);
    printf("разреженная матрица:\n");
    print_matrix(&string, &column, &value);

    printf("введите число, на которое хотите умножить разреженную матрицу: ");
    scanf("%d", &a);
    printf("\n");

    printf("разреженная матрица после преобразования:\n");
    matrix_mult(&value, a);
    print_matrix(&string, &column, &value);


    create_vector(&string_u);
    create_vector(&column_u);
    create_vector(&value_u);
    create_unit_matrix(&string_u, &column_u, &value_u, &string);
    printf("единичная матрица:\n");
    print_matrix(&string_u, &column_u, &value_u);

    printf("введите число, на которое хотите умножить единичную матрицу: ");
    scanf("%d", &b);
    printf("\n");


    printf("единичная матрица после преобразования:\n");
    matrix_mult(&value_u, b);
    print_matrix(&string_u, &column_u, &value_u);

    printf("матрочлен:\n");
    sum(&string_u, &column_u, &value_u,
        &string, &column, &value);


    return 0;
}

