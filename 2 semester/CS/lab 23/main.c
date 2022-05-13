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

bool isEqual(const char *s1, const char *s2) {
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return false;
        ++i;
    }
    return s1[i] == s2[i];
}

int main(int argc, char **argv) {
    tree *t = createTree();
    t->is_unique = false;
    int value;
    while (true) {
        char command[20];
        scanf("%s", &command);
        if (isEqual(command, "h")) {
            help();
        } else if (isEqual(command, "a")) {
            scanf("%d", &value);
            insertNode(t, value);
        } else if (isEqual(command, "p")) {
            printRBTree(t);
        } else if (isEqual(command, "d")) {
            scanf("%d", &value);
            try {
                deleteTreeNode(t, value);
            } catch(RBTREE_NODE_DOES_NOT_EXIST.code) {
                printf("Node with value %d doesn't exists\n", value);
            }
            endtry
        } else if (isEqual(command, "s")) {
            solve(t);
        } else if (isEqual(command, "q")) {
            break;
        } else
            printf("Wrong command, type \"help\" to get info\n");
        fflush(stdin);
    }

    deleteRBTree(t);
    return 0;
}