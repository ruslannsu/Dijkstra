#include "DijkstraAlg.h"
#include "AdjacencyMatrix.h"
#include "BinaryHeap.h"
#include "ShortestPath.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

static int *CreatePredecessors(AdjMatrix *matrix)
{
    int *predecessors = calloc(matrix->n, sizeof(int));
    assert(predecessors != NULL);
    return predecessors;
}

static int *CreateShortestLengths(AdjMatrix *matrix)
{
    int *lengths = calloc(matrix->n, sizeof(int));
    for (int i = 0; i < matrix->n; i++)
    {
        lengths[i] = INT_MAX;
    }
    assert(lengths != NULL);
    return lengths;
}


static bool *CreateVisitedArr(AdjMatrix *matrix)
{
    bool *visited = calloc(matrix->n, sizeof(int));
    assert(visited != NULL);
    return visited;
}

static int FindVertexIndex(int vertex, Heap *heap)
{
    for (int i = 0; i < heap->last_index; i++)
    {
        if (heap->tree[i] == vertex)
        {
            return i;
        }
    }
    return -5;
}

void DijkstraAlg(AdjMatrix *matrix, int path_start, int path_end)
{
    int *lengths = CreateShortestLengths(matrix);
    int *predecessor = CreatePredecessors(matrix);
    bool *visited = CreateVisitedArr(matrix);
    Heap *heap = CreateHeap(matrix->n);
    int vertex = path_start;
    heap->keys[vertex - 1] = 0;
    lengths[vertex - 1] = 0;
    ElementUp(heap, vertex - 1);
    vertex = HeapExtract(heap);
    visited[vertex - 1] = true;
    predecessor[vertex - 1] = vertex;
    while (!IsEmpty(heap))
    {
        for (int j = 0; j < matrix->n; j++)
        {
            if (visited[j] == true)
            {
                continue;
            }
            if (matrix->matrix_src[vertex - 1][j] == 0)
            {
                continue;
            }
            if ((matrix->matrix_src[vertex - 1][j] + heap->keys[vertex - 1]) < heap->keys[j])
            {
                heap->keys[j] = matrix->matrix_src[vertex - 1][j] + heap->keys[vertex - 1];
                predecessor[j] = vertex;
                if (lengths[j] > 0)
                {
                    if (heap->keys[vertex - 1] > 0)
                    {
                        lengths[j] = matrix->matrix_src[vertex - 1][j] + heap->keys[vertex - 1];
                    } 
                    else
                    {
                        lengths[j] = matrix->matrix_src[vertex - 1][j];
                    }
                }
                int vertex_index = FindVertexIndex(j + 1, heap);
                ElementUp(heap, vertex_index);
            }
        }
        vertex = HeapExtract(heap);
        visited[vertex - 1] = true;
    }
    DestroyHeap(heap);
    free(visited);
    Output *output = CreateOutput(matrix, path_start, path_end, lengths, predecessor);
    DestroyMatrix(matrix);
    PrintShortestLengths(output);
    printf("\n");
    PrintShortestPath(output);
    DestroyOutput(output);
}

