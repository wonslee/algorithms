cmake_minimum_required(VERSION 3.23)
project(algorithms)
set(CMAKE_CXX_STANDARD 17)


add_executable(algorithms fileIO/main.cpp)
add_compile_definitions(LOCAL_DEBUG)
add_executable(graph_adjacency_list codes/Graph/graph_adjacency_list.c)
add_executable(kruskal codes/MST/kruskal.c)
add_executable(fileIO_main fileIO/main.cpp)