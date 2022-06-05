#include <iostream>
#include "core.hpp"

using namespace core;
int main() {
    logger::init();
    logger::logInfo("started");
    core::graph g;
    g.load("../data/graph1_branch_8_node.txt");
    solve(g);
    return 0;
}
