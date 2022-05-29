//
// Created by Yeloki on 30.05.2022.
//

#ifndef KP_7_VECTOR_H
#define KP_7_VECTOR_H


#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    int size;
    int num_el;
    int *elem;
} vector;

void create_vector(vector *v);

int empty_vector(vector *v);

int size(vector *v);

void resize(vector *v);

void push_back(vector *v, int value);

void print_vector(vector *v);

void load_matrix(vector *string, vector *column, vector *value);

void create_unit_matrix(vector *string_u, vector *column_u, vector *value_u,
                        vector *string);

void matrix_mult(vector *value, int);

void sum(vector *string_u, vector *column_u, vector *value_u, vector *string, vector *column, vector *value);

void print_matrix(vector *string, vector *column, vector *value);

#endif //KP_7_VECTOR_H
