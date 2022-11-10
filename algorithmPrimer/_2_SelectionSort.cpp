// 实现一个最基本的选择排序（没写完）
#include <iostream>

using namespace std;

void SelectionSort(int* arr, int length)
{
    if (length < 1)
    {
        /* code */
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++)
    {
        /* code */
        int min = arr[i];
        for (int j = i+1; j < length; j++)
        {
            /* code */
            min = min < arr[j] 
        }
        
    }
    
    
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}