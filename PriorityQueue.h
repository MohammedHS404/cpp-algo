#include "HeapElement.h"
class PriorityQueue
{
public:
    HeapElement<int>*arr;
    int maxArraySize;
    int heapSize;
    PriorityQueue();
    PriorityQueue(int n);
    PriorityQueue(HeapElement<int> arr[], int n);
    HeapElement<int> MaxHeapMaximum();
    HeapElement<int> MaxHeapExtractMax();
    void MaxHeapIncreaseKey(HeapElement<int> x, int key);
    void MaxHeapInsert(HeapElement<int> x);
};