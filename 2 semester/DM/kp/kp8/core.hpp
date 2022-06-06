#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "thread_pool.hpp"
#include "debug.hpp"

namespace core {
  struct coord {
    size_t row;
    size_t col;

    template<typename T>
    coord(T _row, T _col) {
      row = _row;
      col = _col;
    }
  };

  class path {
  private:
    size_t _size = 0;
    size_t max_size;
    std::vector<int> data;
    bool is_good = true;
  public:
    explicit path(size_t s) {
      max_size = s;
    }

    [[nodiscard]] size_t getMaxSize() const { return max_size; }


    void add(int node) {
      if (std::count(data.begin(), data.end(), node) == 1)
        is_good = (max_size == _size && data[0] == node);
      data.push_back(node);
      ++_size;
    }

    [[nodiscard]] const std::vector<int> &get() const {
      return data;
    }

    [[nodiscard]] size_t size() const { return _size; }


    [[nodiscard]] bool is_valid() const {
      return is_good;
    }
  };

  std::ostream &operator<<(std::ostream &os, const path &p) {
    for (auto node: p.get())
      os << node << ' ';
    return os;
  }

  path operator*(const path &a, const path &b) {
    path res(a.getMaxSize());
    for (int i(0); i < a.get().size(); ++i)
      res.add(a.get()[i]);
    for (int i(1); i < b.get().size(); ++i)
      res.add(b.get()[i]);
    return res;
  }

  class edge {
  public:
    edge(int f, int s, int c) {
      src = f;
      dest = s;
      cost = c;
    }

    int dest = -1;
    int cost = -1;
    int src = -1;

    [[nodiscard]] path convertEdgeToPath(size_t s) const {
      path res(s);
      res.add(src);
      res.add(dest);
      return res;
    }

  };

  std::ostream &operator<<(std::ostream &fs, const edge &e) {
    fs << "(" << e.src << ", " << e.dest << ")";
    return fs;
  }

  class graph {
  private:
    std::vector<std::vector<int>> adjacency_table;
    std::vector<int> nodes;
    std::vector<edge> edges;
  public:
    int operator[](const coord &c) const {
      return adjacency_table[c.row][c.col];
    }

    edge operator[](size_t n) const {
      return edges[n];
    }

    [[nodiscard]] size_t adjacencyTableSize() const {
      return adjacency_table.size();
    }

    [[nodiscard]] size_t edgesCount() const {
      return edges.size();
    }

    void load(const std::string &filepath) { // check for bad adjacency table not added
      /// \description load graph from file
      /// \param filepath - path to file with graph

      // read all adjacency table from file to vector
      std::ifstream fin(filepath);
      int val;
      std::vector<int> raw_data;
      while (fin >> val)
        raw_data.push_back(val);

      // calculate table size (sqrt from vector adjacencyTableSize)
      auto table_size = static_cast<size_t>(std::sqrt(raw_data.size()));
      logger::logInfo("load adjacency table with adjacencyTableSize: " + std::to_string(table_size) + ", table:");

      // fill the adjacency table
      adjacency_table.resize(table_size);
      for (int i(0); i < table_size; ++i) {
        adjacency_table[i].resize(table_size);
        for (int j(0); j < table_size; ++j) {
          adjacency_table[i][j] = raw_data[i * table_size + j];
          if (adjacency_table[i][j] == -1)
            adjacency_table[i][j] = 0;
          if (i != j && adjacency_table[i][j] != 0)
            edges.emplace_back(i + 1, j + 1, adjacency_table[i][j]);
        }
        logger::logInfo(adjacency_table[i]);
      }
      for (int i(1); i <= table_size; ++i)
        nodes.push_back(i);
      logger::logInfo("Nodes are present:");
      logger::logInfo(nodes);
      logger::logInfo("Edges are present:");
      logger::logInfo(edges);
      logger::logInfo("Graph uploaded successfully");
    } // end load function

  };


  class matrix {
  private:
    std::vector<std::vector<std::vector<path>>> data;
  public:
    [[nodiscard]] size_t size() const {
      return data.size();
    }

    void resize(size_t new_size) {
      data.resize(new_size);
      for (auto &row: data)
        row.resize(new_size);
    }

    std::vector<path> &operator[](const coord &c) {
      return data[c.row][c.col];
    }

    const std::vector<path> &operator[](const coord &c) const {
      return data[c.row][c.col];
    }
  };


  matrix operator*(const matrix &A, const matrix &B) {
    matrix res;
    res.resize(A.size());
    thread_pool pool(16);
    std::vector<std::future<std::pair<std::vector<path>, coord>>> v;
    for (int colA(0); colA < res.size(); ++colA) {
      for (int rowB(0); rowB < res.size(); ++rowB) {
        v.push_back(pool.submit([&, colA, rowB]() {
          std::vector<path> ans;
          for (int index(0); index < res.size(); ++index)
            for (const path &p_l: A[{colA, index}])
              for (const path &p_r: B[{index, rowB}]) {
                auto p = p_l * p_r;
                if (p.is_valid()) {
                  ans.push_back(p);
                }
              }
          return std::pair<std::vector<path>, coord>(ans, {colA, rowB});
        }));
      }
    }
    pool.wait_for_tasks();
    for (auto &c: v) {
      auto data = c.get();
      res[data.second] = data.first;
    }
    return res;
  }

  matrix generateMatrix(const graph &g) {
    matrix res;
    res.resize(g.adjacencyTableSize());
    for (size_t i(0); i < g.edgesCount(); ++i)
      res[{g[i].src - 1, g[i].dest - 1}].push_back(g[i].convertEdgeToPath(g.adjacencyTableSize()));
    logger::logInfo("Successfully create new matrix");
    return res;
  }

  void write_res(const matrix &m) {
    std::ofstream fout("../res.txt");
    for (int i(0); i < m.size(); ++i)
      for (int j(0); j < m.size(); ++j)
        if (m[{i, j}].size())
          fout << m[{i, j}] << std::endl;
  }

  void solve(const graph &g) {
    timer t;
    t.start();
    /// This function finds all the contours of
    /// a given directed graph using the Latin composition method
    /// \param g - graph for Latin composition method
    auto A = generateMatrix(g);
    auto B = generateMatrix(g);
    for (int i(1); i < g.adjacencyTableSize(); ++i) {
      A = A * B;
      logger::logInfo("Multiplication step " + std::to_string(i) + " was completed");
    }
    write_res(A);
    t.stop();
    logger::logInfo("Successfully solved");
    logger::logInfo("Time spent: " + std::to_string(t.ms() / 1000.0) + "s");
  }
} // end namespace core