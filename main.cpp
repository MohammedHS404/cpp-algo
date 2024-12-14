#include <iostream>

void QuickSort(int *arr, int p, int r);

int Partition(int *arr, int p, int r);

main()
{
    int arr[] = {4, 2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    Partition(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}

void QuickSort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}

int Partition(int *arr, int p, int r)
{
    // We start at p-1 becuase we will increment i before we swap
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (arr[j] <= arr[r])
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    i++;
    std::swap(arr[i], arr[r]);

    return i;
}