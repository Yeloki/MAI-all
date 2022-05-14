//
// Created by Yeloki on 08.05.2022.
//

#ifndef LAB_23_QUEUE_H
#define LAB_23_QUEUE_H

#include "../exception/exception.h"
#include <stdbool.h>

/// define для быстрого выброса и поимки ошибок
#define QUEUE_IS_EMPTY  \
  ((struct SxTraceEntry) {300, 0, __FILE__, __LINE__, "\0", NULL})
#define QUEUE_NODE_MEMORY_ALLOCATION_ERROR  \
  ((struct SxTraceEntry) {301, 0, __FILE__, __LINE__, "\0", NULL})
#define QUEUE_MEMORY_ALLOCATION_ERROR  \
  ((struct SxTraceEntry) {302, 0, __FILE__, __LINE__, "\0", NULL})

typedef void* queue_val;

typedef struct queue_node {
    struct queue_node *prev;
    struct queue_node *next;
    queue_val val;
} queue_node;


typedef struct queue {
    queue_node *first;
    queue_node *last;
    size_t size;
} queue;

queue *createQueue();

void pushToQueue(queue *s, queue_val v);

queue_val popFromQueue(queue *s);

void deleteQueue(queue *s);

bool queueIsEmpty(queue *s);


#endif //LAB_23_QUEUE_H
