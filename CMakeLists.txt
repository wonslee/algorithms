cmake_minimum_required(VERSION 3.23)
project(algorithms)
set(CMAKE_CXX_STANDARD 17)


add_executable(algorithms fileIO/main.cpp)
add_compile_definitions(LOCAL_DEBUG)
add_executable(graph_adjacency_list Graph/graph_adjacency_list.c)
add_executable(kruskal MST/kruskal.c)