//
// Created by Yeloki on 06.05.2022.
//

#ifndef UNTITLED1_STACK_H
#define UNTITLED1_STACK_H

#include "../exception/exception.h"
#include <stdbool.h>

/// define для быстрого выброса и поимки ошибок
#define STACK_IS_EMPTY  \
  ((struct SxTraceEntry) {303, 0, __FILE__, __LINE__, "\0", NULL})
#define STACK_NODE_MEMORY_ALLOCATION_ERROR  \
  ((struct SxTraceEntry) {304, 0, __FILE__, __LINE__, "\0", NULL})
#define STACK_MEMORY_ALLOCATION_ERROR  \
  ((struct SxTraceEntry) {305, 0, __FILE__, __LINE__, "\0", NULL})

typedef void* stack_val;

typedef struct stack_node {
    struct stack_node *prev;
    struct stack_node *next;
    stack_val val;
} stack_node;


typedef struct stack {
    stack_node *first;
    stack_node *last;
    size_t size;
} stack;

stack *createStack();

void pushToStack(stack *, stack_val);

stack_val popFromStack(stack *);

void deleteStack(stack *);

bool stackIsEmpty(stack *);

#endif //UNTITLED1_STACK_H
