#include "rbtree.h"
#include "array/array.h"
/// var 9

void solve(tree *t) {
    size_t ans = 0;
    tree_iterator *iter = createTreeIterator(t, t->root);
    while (!iter->end) {
        rbtree_node *n = treeIteratorNext(iter);
        if (n->val == leaf_count(n))
            ans++;
    }
    printf("The number of vertices whose value is the same as its own degree: %u\n", ans);
}

void help() {
    printf((
                   "Using:\n"
                   "h - call this message\n"
                   "a <value> - add value to tree\n"
                   "p - print tree\n"
                   "d <value> - delete ONE node with current value\n"
                   "s - call the \"solve\" function of variant 9\n"
                   "q - quit the program\n"
           ));
}


int main(int argc, char **argv) {
    tree *t = createTree();
    t->is_unique = false;
    int value;
    while (true) {
        char command;
        scanf("%c", &command);
        if (command == 'h') {
            help();
        } else if (command == 'a') {
            scanf("%d", &value);
            insertNode(t, value);
        } else if (command == 'p') {
            printRBTree(t);
        } else if (command == 'd') {
            scanf("%d", &value);
            try {
                deleteTreeNode(t, value);
            } catch(RBTREE_NODE_DOES_NOT_EXIST.code) {
                printf("Node with value %d doesn't exists\n", value);
            }
            endtry
        } else if (command == 's') {
            solve(t);
        } else if (command == 'q') {
            break;
        } else
            printf("Wrong command, type \"help\" to get info\n");
        fflush(stdin);
    }

    deleteRBTree(t);
    return 0;
}