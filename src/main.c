#include "AdjacencyMatrix.h"
#include "DijkstraAlg.h"
#include "Errors.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }
    if (n == 0)
    {
        printf("bad vertex");
        return 0;
    }
    if (!VerticesError(n))
    {
        printf("bad number of vertices");
        return 0;
    }
    int path_start, path_end;
    if (scanf("%d %d", &path_start, &path_end) != 2)
    {
        return 0;
    }
    int m;
    if (scanf("%d", &m) != 1)
    {
        return 0;
    }
    if (!EdgeError(n, m))
    {
        printf("bad number of edges");
        return 0;
    }
    AdjMatrix *matrix = CreateAdjMatrix(n);
    int start, end, length = 0;
    int edge_counter = 0;
    unsigned long long t_length;
    for (int i = 0; i < m; i++)
        {
        if (scanf("%d %d %llu", &start, &end, &t_length) == 3)
        {
            edge_counter++;
            if (t_length > INT_MAX)
            {
                printf("bad length");
                DestroyMatrix(matrix);
                return 0;
            } 
            else
            {
                length = t_length;
            }
            if (!VertexError(start, end, n))
            {
                printf("bad vertex");
                DestroyMatrix(matrix);
                return 0;
            }
            if (length == INT_MAX)
            {
                length--;
            }
            AddMatrixValue(matrix, start - 1, end - 1, length);
        }
    }
    if (edge_counter != m)
    {
        printf("bad number of lines");
        DestroyMatrix(matrix);
        return 0;
    }
    DijkstraAlg(matrix, path_start, path_end);
    return 0;
}
