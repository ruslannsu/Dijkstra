#include "BinaryHeap.h"
#include "stdlib.h"
#include <assert.h>
#include <limits.h>

Heap *CreateHeap(int size)
{
    Heap *heap = malloc(sizeof(Heap));
    assert(heap != NULL);
    heap->tree = calloc(size, sizeof(int));
    assert(heap->tree != NULL);
    heap->keys = calloc(size, sizeof(int));
    assert(heap->keys != NULL);
    heap->size = size;
    heap->last_index = 0;
    for (int i = 0; i < size; i++)
    {
        heap->tree[i] = i + 1;
        heap->keys[i] = INT_MAX;
        heap->last_index++;
    }
    return heap;
}

static void Swap(int index_1, int index_2, Heap *heap)
{
    int temp = heap->tree[index_1];
    heap->tree[index_1] = heap->tree[index_2];
    heap->tree[index_2] = temp;
}

void ElementUp(Heap *heap, int last_index)
{
    int i = last_index;
    while (heap->keys[heap->tree[i] - 1] < heap->keys[heap->tree[((i - 1) / 2)] - 1])
    {
        Swap(i, (i - 1) / 2, heap);
        i = (i - 1) / 2;
    }
}

static void ElementDown(Heap *heap, int index)
{
    while ((index * 2 + 1) < heap->last_index)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int j = left;
        if (right < heap->last_index && (heap->keys[heap->tree[right] - 1] < heap->keys[heap->tree[left] - 1]))
        {
            j = right;
        }
        if (heap->keys[heap->tree[index] - 1] <= heap->keys[heap->tree[j] - 1])
        {
            break;
        }
        Swap(index, j, heap);
        index = j;
    }
}


int HeapExtract(Heap *heap)
{
    int temp_root = heap->tree[0];
    heap->tree[0] = heap->tree[heap->last_index - 1];
    heap->last_index--;
    ElementDown(heap, 0);
    return temp_root;
}

bool IsEmpty(Heap *heap)
{
    return (heap->last_index == 0);
}

void DestroyHeap(Heap *heap)
{
    free(heap->tree);
    free(heap);
}
