/*
如何把一个int类型的数，提取出最右侧的1来
*/
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int a = 198;
    cout << "a的二进制形式为:   " << (bitset<16>)a << endl;
    int res = a & (-a);
    cout << "res的二进制形式为: " << (bitset<16>)res << endl;

    return 0;
}