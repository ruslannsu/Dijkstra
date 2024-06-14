#pragma once

typedef struct AdjMatrix
{
    int n;
    int **matrix_src;
} AdjMatrix;

AdjMatrix *CreateAdjMatrix(int n);

void AddMatrixValue(AdjMatrix *matrix, int node_1, int node_2, int length);

void DestroyMatrix(AdjMatrix *matrix);


