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

#include "dijkstra_node.hpp"

void DijkstraNode::userInput()
{
  int src, dst, weight, num_edges;

  try {
    std::cout << "Enter the number of nodes: ";
    std::cin >> _num_nodes;
    if (_num_nodes < 0) {
      throw std::invalid_argument("Number of nodes must not be negative.");
    }
    _graph_matrix.resize(_num_nodes, std::vector<int>(_num_nodes, -1));

    std::cout << "Enter the number of edges: ";
    std::cin >> num_edges;
    if (num_edges < 0) {
      throw std::invalid_argument("Number of edges must not be negative.");
    }

    std::cout << "Enter the source of node: ";
    std::cin >> _src_node;
    if (_src_node < 0 || _src_node >= _num_nodes) {
      throw std::invalid_argument("Source node must be within the range of existing nodes.");
    }

    for (int i = 0; i < num_edges; i++) {
      std::cout << "Enter edge " << i + 1 << " (source, destination, weight): ";
      std::cin >> src >> dst >> weight;

      if (src < 0 || src >= _num_nodes || dst < 0 || dst >= _num_nodes || weight < 0) {
        throw std::invalid_argument(
          "Invalid edge details. 'source' and 'destination' should be within the range of existing "
          "nodes, and 'weight' must not be negative.");
      }

      _graph_matrix[src][dst] = weight;
      _graph_matrix[dst][src] = weight;
    }
  } catch (const std::invalid_argument & e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

void DijkstraNode::solveDijkstra()
{
  std::vector<int> distance(_num_nodes, INT_MAX);
  std::vector<bool> shortest_path_nodes(_num_nodes, false);
  distance[_src_node] = 0;

  int min_dist_index;
  while ((min_dist_index = minDistance(distance, shortest_path_nodes)) != -1) {
    shortest_path_nodes[min_dist_index] = true;
    updateDistance(min_dist_index, distance, shortest_path_nodes);
  }
  saveResult(distance);
}

int DijkstraNode::minDistance(const std::vector<int> & dist, const std::vector<bool> & nodes)
{
  int min = INT_MAX;
  int min_index = -1;

  for (int v = 0; v < _num_nodes; v++) {
    if (!nodes[v] && dist[v] <= min) {
      min = dist[v], min_index = v;
    }
  }

  return min_index;
}

void DijkstraNode::updateDistance(
  const int index, std::vector<int> & dist, const std::vector<bool> & nodes)
{
  for (int v = 0; v < _num_nodes; v++) {
    if (
      !nodes[v] && _graph_matrix[index][v] != -1 &&
      dist[index] + _graph_matrix[index][v] < dist[v]) {
      dist[v] = dist[index] + _graph_matrix[index][v];
    }
  }
}

void DijkstraNode::saveResult(const std::vector<int> & dist)
{
  std::cout << "========== RESULT ==========\n";
  std::cout << "Node \t Distance from Source\n";
  for (int i = 0; i < _num_nodes; i++) {
    std::cout << i << " \t\t " << dist[i] << "\n";
  }

  graph_t g(_num_nodes);
  std::map<graph_t::edge_descriptor, std::string> edge_labels;
  std::map<graph_t::vertex_descriptor, std::string> node_labels;

  for (int i = 0; i < _num_nodes; ++i) {
    node_labels[i] = std::to_string(i) + " (Dist: " + std::to_string(dist[i]) + ")";
    for (int j = i + 1; j < _num_nodes; ++j) {
      if (_graph_matrix[i][j] != -1) {
        auto e = add_edge(i, j, _graph_matrix[i][j], g).first;
        edge_labels[e] = std::to_string(_graph_matrix[i][j]);
      }
    }
  }

  std::ofstream file("graph.dot");
  std::cout << "Saving graph...\n";
  boost::write_graphviz(
    file, g, boost::make_label_writer(boost::make_assoc_property_map(node_labels)),
    boost::make_label_writer(boost::make_assoc_property_map(edge_labels)));
  std::cout << "Done.\n";
}

int main(int argc, char ** argv)
{
  DijkstraNode DN;
  DN.userInput();
  DN.solveDijkstra();
  return 0;
}
