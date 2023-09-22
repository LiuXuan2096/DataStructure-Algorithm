/*
一个数组中有一种数出现K次，其他数都出现了M次，
已知M > 1，K < M，找到出现了K次的数
要求额外空间复杂度O(1)，时间复杂度O(N)
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m = 4;
    vector<int> nums = {235,235,235,34,34,34,34,5,5,5,5,67,67,67,67,87,87,87,87};
    int help[32] = {0};
    for (int v : nums)
    {
        for(int i = 0; i <= 31; ++i)
        {
            if (((v >> i) & 1) != 0)
            {
                help[i]++;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 32; ++j)
    {
        if (help[j] % m != 0)
        {
            ans = ans | (1 << j);
        }
    }
    cout << "出现k次的数为: " << ans << endl;

    return 0; 
}