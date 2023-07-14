# Tested on Ubuntu-20.04
cmake -S . -B build
cmake --build build
cd ./build/
mv dijkstra ../dijkstra.out
