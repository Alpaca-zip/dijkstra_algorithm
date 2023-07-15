cmake_minimum_required(VERSION 3.0.2)
project(dijkstra)

find_package(Boost REQUIRED COMPONENTS graph)

# Setting the include paths
include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)

# Setting up the executable
add_executable(dijkstra src/dijkstra_node.cpp)

# Linking the libraries
target_link_libraries(dijkstra ${Boost_LIBRARIES})
