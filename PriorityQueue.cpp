#include "HeapElement.h"
#include <iostream>
#include "heapFunctions.h"
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    heapSize = 0;
    maxArraySize = 0;
    arr = new HeapElement<int>[maxArraySize];
};

PriorityQueue::PriorityQueue(int maxArraySize)
{
    heapSize = 0;
    this->maxArraySize = maxArraySize;
    arr = new HeapElement<int>[maxArraySize];
};

HeapElement<int> PriorityQueue::MaxHeapMaximum()
{
    if (heapSize < 1)
    {
        std::cout << "Heap is empty" << std::endl;
        return HeapElement<int>();
    }
    return arr[0];
};

HeapElement<int> PriorityQueue::MaxHeapExtractMax()
{
    if (heapSize < 1)
    {
        std::cout << "Heap is empty" << std::endl;
        return HeapElement<int>();
    }

    HeapElement<int> max = arr[0];

    arr[0] = arr[heapSize - 1];

    heapSize--;

    maxHeapify<int>(arr, heapSize, 0);

    return max;
};

void PriorityQueue::MaxHeapIncreaseKey(HeapElement<int> x, int key)
{
    if (key < x.key)
    {
        std::cout << "New key is smaller than current key" << std::endl;
        return;
    }

    int i = -1;

    for (int j = 0; j < heapSize; j++)
    {
        if (arr[j].key == x.key)
        {
            i = j;
            break;
        }
    }

    arr[i].key = key;

    while (i > 0 && arr[parent(i)].key < arr[i].key)
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
};

void PriorityQueue::MaxHeapInsert(HeapElement<int> x)
{
    if (heapSize == maxArraySize)
    {
        std::cout << "Heap is full" << std::endl;
        return;
    }

    heapSize++;

    arr[heapSize].key = INT_MIN;

    MaxHeapIncreaseKey(arr[heapSize], x.key);
};