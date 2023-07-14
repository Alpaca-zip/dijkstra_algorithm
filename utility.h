#pragma once

#include <boost/graph/graphviz.hpp>
#include <boost/range/adaptor/indexed.hpp>
#include <climits>
#include <iostream>
#include <vector>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, int64_t, int64_t>
  graph_t;

class DijkstraNode
{
private:
  int _num_nodes, _src_node, _dst_node;
  std::vector<std::vector<int>> _graph_matrix;

public:
  void userInput();
  void solveDijkstra();
  void printResult(const std::vector<int> & dist);
  int minDistance(const std::vector<int> & dist, const std::vector<bool> & shortestPathNodes);
};
