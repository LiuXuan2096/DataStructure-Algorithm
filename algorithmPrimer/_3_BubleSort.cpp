// 实现一个简单的冒泡排序
#include <iostream>

using namespace std;

void swap(int* arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubleSort(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        /* code */
        for (int j = i+1; j < length; j++)
        {
            /* code */
            if (arr[i] > arr[j])
            {
                /* code */
                swap(arr, i, j);
            }
            
        }
        
    }
    
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

int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << "before: ";
    show_arr(arr, 10);
    bubleSort(arr, 10);
    cout << "after: ";
    show_arr(arr, 10);

    return 0;
}