# dijkstra_algorithm [![Build Check Bot](https://github.com/Alpaca-zip/dijkstra_algorithm/actions/workflows/build-check-bot.yml/badge.svg)](https://github.com/Alpaca-zip/dijkstra_algorithm/actions/workflows/build-check-bot.yml)
This repository contains an implementation of Dijkstra's Algorithm in C++.

## How to Use

### 1. Clone this repository.
```
$ git clone https://github.com/Alpaca-zip/dijkstra_algorithm.git
```
### 2. Compile the program using a C++ compiler.
```
$ build.sh
```
### 3. Run the program. 
You will be prompted to input the number of nodes, the number of edges, and the source node. For each edge, you should specify the source node, the destination node, and the weight of the edge.
The program will calculate and print the shortest distance from the source node to all other nodes.
```
$ run.sh
Enter the number of nodes: 5
Enter the number of edges: 7
Enter the source of node: 0
Enter edge 1 (source, destination, weight): 0 1 7
Enter edge 2 (source, destination, weight): 0 2 4
Enter edge 3 (source, destination, weight): 0 3 3
Enter edge 4 (source, destination, weight): 1 2 1
Enter edge 5 (source, destination, weight): 1 4 2
Enter edge 6 (source, destination, weight): 2 4 6
Enter edge 7 (source, destination, weight): 3 4 5
========== RESULT ==========
Node     Distance from Source
0                0
1                5
2                4
3                3
4                7
Saving graph...
Done.
```
### 4. The results will be saved as `graph.pdf`.
<img src="https://github.com/Alpaca-zip/dijkstra_algorithm/assets/84959376/cf02d929-a46f-46b1-b935-4193ed38787d" width="400px">
