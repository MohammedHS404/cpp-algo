#include "./HeapElement.h"

template <typename T>
void HeapSort(HeapElement<T> arr[], int n, bool isMax);
template <typename T>
void buildHeap(HeapElement<T> arr[], int n, bool isMax);
template <typename T>
void maxHeapify(HeapElement<T> arr[], int n, int i);
template <typename T>
void minHeapify(HeapElement<T> arr[], int n, int i);
template <typename T>
void swap(HeapElement<T> &a, HeapElement<T> &b);
int leftChild(int i);
int rightChild(int i);
int parent(int i);
template <typename T>
void printTreeBFS(HeapElement<T> arr[], int n);