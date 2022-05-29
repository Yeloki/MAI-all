//
// Created by Yeloki on 30.05.2022.
//

#include "table.h"

bool exists(double keys[], double item, int n) {
    for (int i = 0; i < n; i++) {
        if (item == keys[i]) {
            return true;
        }
    }
    return false;
}

int binary_search(double keys[], double item, int low, int high) {
    if (high <= low) {
        if (item > keys[low]) {
            return low + 1;
        } else {
            return low;
        }
    }
    int mid = (low + high) / 2;
    if (item == keys[mid]) {
        return mid;
    }
    if (item > keys[mid]) {
        return binary_search(keys, item, mid + 1, high);
    }
    return binary_search(keys, item, low, mid - 1);
}

bool is_sorted(double keys[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (keys[i] > keys[i + 1]) {
            return false;
        }
    }
    return true;
}

bool is_reversed(double keys[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (keys[i] < keys[i + 1]) {
            return false;
        }
    }
    return true;
}

void swap_key(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_line(line *a, line *b) {
    line tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse_array(double keys[], int n, line table[]) {
    for (int i = 0; i < n / 2; i++) {
        swap_key(&keys[i], &keys[n - 1 - i]);
        swap_line(&table[i], &table[n - 1 - i]);

    }
}

void selection_sort_with_exchanges(double keys[], int n, line table[]) {
    if (is_sorted(keys, n)) {
        return;
    }
    if (is_reversed(keys, n)) {
        reverse_array(keys, n, table);
        return;
    }
    for (int i = 0; i < n; i++) {
        double min_key = keys[i], tmp;
        int pos = i; // pos - position of minimal key
        line min_line = table[i], tmp_line;
        for (int j = i; j < n; j++) {
            if (keys[j] < min_key) {
                min_key = keys[j];
                min_line = table[j];
                pos = j;
            }
        }
//change min and element from it's position
        tmp = keys[i];
        tmp_line = table[i];

        keys[i] = min_key;
        table[i] = min_line;

        keys[pos] = tmp;
        table[pos] = tmp_line;
    }
}
