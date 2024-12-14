#ifndef HEAP_ELEMENT_H
#define HEAP_ELEMENT_H

template <typename T>
class HeapElement
{
public:
    int key;
    T value;
    HeapElement();
    HeapElement(int key, T value);
};

#endif // HEAP_ELEMENT_H