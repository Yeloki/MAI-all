#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include "rbtree.h"
#include <assert.h>
#include "queue/queue.h"


int main(int argc, char **argv) {
    tree *t = createTree();
    for (int i = 0; i <= 100; ++i) {
        insertNode(t, i);
    }
    for (int i = 0; i <= 100; ++i) {
        insertNode(t, i);
    }
    printRBTree(t);
    deleteRBTree(t);
    return 0;
}