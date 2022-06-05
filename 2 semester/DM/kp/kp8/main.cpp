#include <iostream>
#include "core.hpp"

using namespace core;

int main() {
  logger::init();
  logger::logInfo("started");
  core::graph g;
  g.load("../data/graph.txt");
  solve(g);
  return 0;
}
