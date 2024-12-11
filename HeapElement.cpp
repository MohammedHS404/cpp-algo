#include "./HeapElement.h"

template <typename T>
HeapElement<T>::HeapElement()
{
    key = 0;
    value = 0;
};

template <typename T>
HeapElement<T>::HeapElement(int key, T value)
{
    this->key = key;
    this->value = value;
};

template class HeapElement<int>;