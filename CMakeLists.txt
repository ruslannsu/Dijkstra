cmake_minimum_required(VERSION 3.26)
project(Dijkstra C)

set(CMAKE_C_STANDARD 99)

add_executable(Dijkstra main.c
        AdjacencyMatrix.c
        AdjacencyMatrix.h
        BinaryHeap.c
        BinaryHeap.h
        DijkstraAlg.c
        DijkstraAlg.h
        Errors.c
        Errors.h
        ShortestPath.c
        ShortestPath.h)
