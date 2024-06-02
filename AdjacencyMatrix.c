#include "AdjacencyMatrix.h"
#include <stdlib.h>
#include <assert.h>

AdjMatrix *CreateAdjMatrix(int n)
{
    AdjMatrix * matrix_ptr = malloc(sizeof(AdjMatrix));
    assert(matrix_ptr != NULL);
    int **matrix_src = malloc(n * sizeof(int*) + n * n * sizeof(int));
    assert(matrix_src != NULL);
    int *p = (int *) (matrix_src + n);
    for (int i = 0; i < n; i++)
    {
        matrix_src[i] = p;
        for (int j = 0; j < n; j++)
        {
            matrix_src[i][j] = 0;
        }
        p = p + n;
    }
    matrix_ptr->n = n;
    matrix_ptr->matrix_src = matrix_src;
    return matrix_ptr;
}

void AddMatrixValue(AdjMatrix *matrix, int node_1, int node_2, int length)
{
    matrix->matrix_src[node_1][node_2] = length;
    matrix->matrix_src[node_2][node_1] = length;
}

void DestroyMatrix(AdjMatrix *matrix)
{
    free(matrix->matrix_src);
    free(matrix);
}
