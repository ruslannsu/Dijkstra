#include "ShortestPath.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

static bool IsPathExist(int vertex, Output *output)
{
    int temp_vertex = vertex;
    while (true)
    {
        if (output->predecessors[temp_vertex - 1] == output->path_start)
        {
            return true;
        }
        if (output->predecessors[temp_vertex - 1] == 0)
        {
            return false;
        }
        temp_vertex = output->predecessors[temp_vertex - 1];
    }
}

static bool IsOverflow(Output *output)
{
    if (output->lengths[output->path_end - 1] >= 0)
    {
        return false;
    }
    int overflow_counter = 0;
    for (int i = 0; i < output->vertex_count; i++)
    {
        if ((i != output->path_end - 1) && ((output->lengths[i] == INT_MAX) || (output->lengths[i] < 0)) && (IsPathExist(i + 1, output)))
        {
            overflow_counter++;
            if (overflow_counter >= 2)
            {
                return true;
            }
        }
    }
    return false;
}

Output *CreateOutput(AdjMatrix *matrix, int path_start, int path_end, int *lengths, int *predecessor)
{
    Output *output = malloc(sizeof(Output));
    assert(output != NULL);
    output->lengths = lengths;
    output->predecessors = predecessor;
    output->vertex_count = matrix->n;
    output->path_start = path_start;
    output->path_end = path_end;
    output->main_path_not_exist = false;
    return output;
}
void DestroyOutput(Output *output)
{
    free(output->lengths);
    free(output->predecessors);
    free(output);
}

void PrintShortestLengths(Output *output)
{
    for (int i = 0; i < output->vertex_count; i++)
    {
        if (!IsPathExist(i + 1, output))
        {
            if ((i + 1) == output->path_end)
            {
                output->main_path_not_exist = true;
            }
            printf("oo ");
            continue;
        }
        if (output->lengths[i] < 0)
        {
            printf("INT_MAX+ ");
        }
        else
        {
            if (output->lengths[i] + 1 == INT_MAX)
            {
                output->lengths[i]++;
                printf("%d ", output->lengths[i]);
            }
            else
            {
                printf("%d ", output->lengths[i]);
            }
        }
    }
}

void PrintShortestPath(Output *output)
{
    if (output->main_path_not_exist)
    {
        printf("no path");
        return;
    }

    if (IsOverflow(output))
    {
        printf("overflow");
        return;
    }
    if (output->path_start == output->path_end)
    {
        printf("%d", output->path_end);
        return;
    }
    if (output->predecessors[output->path_end - 1] == output->path_start)
    {
        printf("%d ", output->path_end);
        printf("%d ", output->path_start);
        return;
    }
    int temp_path_end = output->path_end;
    printf("%d ", output->path_end);
    while (true)
    {
        if (output->predecessors[temp_path_end - 1] == output->path_start)
        {
            printf("%d ", output->path_start);
            break;
        }
        printf("%d ", output->predecessors[temp_path_end - 1]);
        temp_path_end = output->predecessors[temp_path_end - 1];
    }
}
