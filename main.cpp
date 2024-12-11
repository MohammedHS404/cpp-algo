#include <iostream>
#include "./HeapElement.h"
#include "./heapFunctions.h"
#include "./PriorityQueue.h"

main()
{
    PriorityQueue pq(10);

    pq.MaxHeapInsert(HeapElement<int>(1, 1));

    pq.MaxHeapInsert(HeapElement<int>(2, 2));

    pq.MaxHeapInsert(HeapElement<int>(3, 3));

    pq.MaxHeapInsert(HeapElement<int>(4, 4));

    pq.MaxHeapInsert(HeapElement<int>(5, 5));

    printTreeBFS(pq.arr, pq.heapSize);

    // now we have a max heap with 5 elements

    std::cout << "Max element: " << pq.MaxHeapMaximum().key << std::endl;

    std::cout << "Extracting max element: " << pq.MaxHeapExtractMax().key << std::endl;

    std::cout << "Max element: " << pq.MaxHeapMaximum().key << std::endl;

    pq.MaxHeapIncreaseKey(HeapElement<int>(3, 3), 10);

    std::cout << "Max element: " << pq.MaxHeapMaximum().key << std::endl;

    pq.MaxHeapIncreaseKey(HeapElement<int>(3, 3), 2);

    std::cout << "Max element: " << pq.MaxHeapMaximum().key << std::endl;

    return 0;
}