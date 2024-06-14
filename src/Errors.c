#include "Errors.h"


bool VerticesError(int n)
{
    if ((n > 5000) || (n < 0))
    {
        return false;
    }
    return true;
}

bool EdgeError(int n, int m)
{
    if ((m < 0) || (m > (n * (n + 1) / 2)))
    {
        return false;
    }
    return true;
}

bool VertexError(int node_1, int node_2, int n)
{
    if ((node_1 > n) || (node_1 < 1))
    {
        return false;
    }
    if ((node_2 > n) || (node_2 < 1))
    {
        return false;
    }
    return true;
}

