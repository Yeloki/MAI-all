#include "rbtree.h"

/// var 9

size_t solve(tree *t) {
    size_t ans = 0;
    tree_iterator *iter = createTreeIterator(t, t->root);
    while (!iter->end) {
        rbtree_node *n = treeIteratorNext(iter);
        if (n->val == leaf_count(n))
            ans++;
    }
    return ans;
}

int main(int argc, char **argv) {
    tree *t = createTree();
    t->is_unique = false;
    for (int i = 0; i <= 100; ++i)
        insertNode(t, 2);
    for (int i = 0; i <= 100; ++i)
        insertNode(t, 1);
    printRBTree(t);
    printf("The number of vertices whose value is the same as its own degree: %u", solve(t));
    deleteRBTree(t);
    return 0;
}