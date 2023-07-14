/*
  Copyright 2023 Alapaca-zip

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

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
