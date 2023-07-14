#include "utility.h"

void DijkstraNode::userInput()
{
  int src, dst, weight, num_edges;

  std::cout << "Enter the number of nodes: ";
  std::cin >> _num_nodes;
  _graph_matrix.resize(_num_nodes, std::vector<int>(_num_nodes, 0));

  std::cout << "Enter the number of edges: ";
  std::cin >> num_edges;

  std::cout << "Enter the source of node: ";
  std::cin >> _src_node;

  for (int i = 0; i < num_edges; i++) {
    std::cout << "Enter edge " << i + 1 << " (source, destination, weight): ";
    std::cin >> src >> dst >> weight;

    while (src < 0 || src >= _num_nodes || dst < 0 || dst >= _num_nodes) {
      std::cout << "Invalid source or destination node. Please enter nodes in "
                   "range 0 to "
                << _num_nodes - 1 << "\n";
      std::cout << "Enter edge " << i + 1 << " (source, destination, weight): ";
      std::cin >> src >> dst >> weight;
    }

    _graph_matrix[src][dst] = weight;
    _graph_matrix[dst][src] = weight;
  }
}

void DijkstraNode::solveDijkstra()
{
  std::vector<int> dist(_num_nodes, INT_MAX);
  std::vector<bool> shortestPathNodes(_num_nodes, false);
  dist[_src_node] = 0;

  int u;
  while ((u = minDistance(dist, shortestPathNodes)) != -1) {
    shortestPathNodes[u] = true;
    for (int v = 0; v < _num_nodes; v++) {
      if (!shortestPathNodes[v] && _graph_matrix[u][v] && dist[u] + _graph_matrix[u][v] < dist[v]) {
        dist[v] = dist[u] + _graph_matrix[u][v];
      }
    }
  }
  printResult(dist);
}

int DijkstraNode::minDistance(
  const std::vector<int> & dist, const std::vector<bool> & shortestPathNodes)
{
  int min = INT_MAX;
  int min_index = -1;

  for (int v = 0; v < _num_nodes; v++) {
    if (!shortestPathNodes[v] && dist[v] <= min) {
      min = dist[v], min_index = v;
    }
  }

  return min_index;
}

void DijkstraNode::printResult(const std::vector<int> & dist)
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
      if (_graph_matrix[i][j] != 0) {
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
