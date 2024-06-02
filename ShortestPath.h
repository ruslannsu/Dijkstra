#pragma once
#include "AdjacencyMatrix.h"
#include <stdbool.h>

typedef struct Output
{
    int path_start;
    int path_end;
    int vertex_count;
    int *lengths;
    int *predecessors;
    bool main_path_not_exist;

} Output;

Output *CreateOutput(AdjMatrix *matrix, int path_start, int path_end, int *lengths, int *predecessor);

void DestroyOutput(Output *output);

void PrintShortestLengths(Output *output);

void PrintShortestPath(Output *output);




