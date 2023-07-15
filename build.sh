# Tested on Ubuntu-20.04
# Tested on Ubuntu-22.04
cmake -S . -B build
cmake --build build
cd ./build/
mv dijkstra ../dijkstra.out
