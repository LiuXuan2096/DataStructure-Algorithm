// 打印出32位整形数字的二进制表示
#include <iostream>

using namespace std;

void printBinary_32(int n)
{
    int temp = 0;
    char bit = '0';
    for (int i = 31; i >= 0; i--)
    {
        /* code */
        temp = n & (1 << i);
        bit = (0 == temp) ? '0' : '1';
        cout << bit; 
    }
    cout << endl;
}

int main()
{
    printBinary_32(1024);
    
    return 0;
}