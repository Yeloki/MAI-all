//
// Created by Yeloki on 30.05.2022.
//

#ifndef KP_9_TABLE_H
#define KP_9_TABLE_H

#include <stdio.h>
#include <stdbool.h>

typedef struct line {
    char data[100];
} line;


bool exists(double keys[], double item, int n);

int binary_search(double keys[], double item, int low, int high);

bool is_sorted(double keys[], int n);

bool is_reversed(double keys[], int n);

void swap_key(double *a, double *b);

void swap_line(line *a, line *b);

void reverse_array(double keys[], int n, line table[]);

void selection_sort_with_exchanges(double keys[], int n, line table[]);

#endif //KP_9_TABLE_H
