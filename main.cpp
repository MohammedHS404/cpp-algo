#include <iostream>
#include "./HeapElement.h"
#include "./heap.h"

HeapElement<int> MaxHeapMaximum(HeapElement<int> arr[], int n);
HeapElement<int> MaxHeapExtractMax(HeapElement<int> arr[], int n);
void MaxHeapIncreaseKey(HeapElement<int> arr[], int n, HeapElement<int> x, int key);
void MaxHeapInsert(HeapElement<int> arr[], int n, HeapElement<int> x);

main()
{
    HeapElement<int> arr[] = {{10, 10}, {9, 9}, {8, 8}, {7, 7}, {6, 6}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};

    int n = sizeof(arr) / sizeof(arr[0]);
    bool isMax = true;

    printTreeBFS<int>(arr, n);
    MaxHeapInsert(arr, n, {11, 11});
    printTreeBFS<int>(arr, n);
    return 0;
}

HeapElement<int> MaxHeapMaximum(HeapElement<int> arr[], int n)
{
    if (n < 1)
    {
        std::cout << "Heap is empty" << std::endl;
        return HeapElement<int>();
    }
    return arr[0];
}

HeapElement<int> MaxHeapExtractMax(HeapElement<int> arr[], int n)
{
    if (n < 1)
    {
        std::cout << "Heap is empty" << std::endl;
        return HeapElement<int>();
    }

    HeapElement<int> max = arr[0];

    arr[0] = arr[n - 1];

    n--;

    maxHeapify<int>(arr, n, 0);

    return max;
}

void MaxHeapIncreaseKey(HeapElement<int> arr[], int n, HeapElement<int> x, int key)
{
    if (key < x.key)
    {
        std::cout << "New key is smaller than current key" << std::endl;
        return;
    }

    int i = -1;

    for (int j = 0; j < n; j++)
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
}

void MaxHeapInsert(HeapElement<int> arr[], int n, HeapElement<int> x)
{
    n++;
    arr[n - 1].key = INT_MIN;
    MaxHeapIncreaseKey(arr, n, x, x.key);
}