// 实现一个简单的插入排序
#include <iostream>

using namespace std;

void swap(int* arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void show_arr(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        /* code */
        if (0 == i)
        {
            /* code */
            cout << "[";
        }
        cout << " " << arr[i];
        if (length - 1 == i)
        {
            /* code */
            cout << " ]" << endl; 
        }
        
    }
}

void insertion_sort(int* arr, int length)
{
    if (arr == NULL || length < 2)
    {
        /* code */
        return;
    }
    for (int i = 1; i < length; i++)
    {
        /* code */
        for (int preIndex = i-1; preIndex >= 0 && arr[preIndex] > arr[preIndex+1]; preIndex--)
        {
            /* code */
            swap(arr, preIndex, preIndex+1);
        }
        
    }
    
    
}

int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << "before: ";
    show_arr(arr, 10);
    insertion_sort(arr, 10);
    cout << "after: ";
    show_arr(arr, 10);

    return 0;
}