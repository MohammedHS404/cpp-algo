#include <iostream>
#include "./HeapElement.h"
#include "./heap.h"

template <typename T>
void HeapSort(HeapElement<T> arr[], int n, bool isMax)
{
    buildHeap(arr, n, isMax);
    if (isMax)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            minHeapify(arr, i, 0);
        }
    }
}

template <typename T>
void buildHeap(HeapElement<T> arr[], int n, bool isMax)
{
    if (isMax)
    {
        for (int i = n / 2; i >= 0; i--)
        {
            maxHeapify(arr, n, i);
        }
    }
    else
    {
        for (int i = n / 2; i >= 0; i--)
        {
            minHeapify(arr, n, i);
        }
    }
}

template <typename T>
void maxHeapify(HeapElement<T> arr[], int n, int i)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < n && arr[left].key > arr[largest].key)
    {
        largest = left;
    }

    if (right < n && arr[right].key > arr[largest].key)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

template <typename T>
void minHeapify(HeapElement<T> arr[], int n, int i)
{
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < n && arr[left].key < arr[smallest].key)
    {
        smallest = left;
    }

    if (right < n && arr[right].key < arr[smallest].key)
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

template <typename T>
void swap(HeapElement<T> &a, HeapElement<T> &b)
{
    HeapElement<T> temp = a;
    a = b;
    b = temp;
}

int leftChild(int i)
{
    return 2 * i + 1;
}

int rightChild(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

template <typename T>
void printTreeBFS(HeapElement<T> arr[], int n)
{
    std::cout << "Printing tree BFS";
    int level = 0;
    int i = 0;

    while (i < n)
    {
        for (int j = 0; j < level; j++)
        {
            if (i >= n)

            {
                break;
            }
            std::cout << "(" << arr[i].key << "," << arr[i].value << ")" << " ";
            i++;
        }
        std::cout << std::endl;
        level++;
    }

    std::cout << "Printing Array" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "(" << arr[i].key << "," << arr[i].value << ")" << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
};

template void HeapSort(HeapElement<int> arr[], int n, bool isMax);
template void buildHeap(HeapElement<int> arr[], int n, bool isMax);
template void maxHeapify(HeapElement<int> arr[], int n, int i);
template void minHeapify(HeapElement<int> arr[], int n, int i);
template void swap(HeapElement<int> &a, HeapElement<int> &b);
template void printTreeBFS(HeapElement<int> arr[], int n);
