#pragma once
#include <stdbool.h>

typedef struct Heap
{
    int last_index;
    int size;
    int *tree;
    int *keys;
} Heap;

Heap *CreateHeap(int size);

Heap *HeapAdd(int vertex, Heap *heap);

void DestroyHeap(Heap *heap);

void ElementUp(Heap *heap, int last_index);

bool IsEmpty(Heap * heap);

int HeapExtract(Heap *heap);
