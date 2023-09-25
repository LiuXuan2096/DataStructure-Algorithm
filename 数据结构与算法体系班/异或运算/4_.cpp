///*
//有这样一个数组，其中只有a 和 b两个数出现了奇数次，其他数字出现了偶数次
//找出 a 和 b分别是谁？
//*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    vector<int> nums = {6,6,6,123,123,123,56,56,78,78,78,78,98,98,45,45};
//    int a_xor_b = 0;
//    for (int v : nums)
//    {
//        a_xor_b = a_xor_b ^ v;
//    }
//    // 循环结束后 得到a^b的值
//    cout << "a_xor_b: " << a_xor_b << endl;
//    int right_one = a_xor_b & (-a_xor_b); // 得到a和b异或的结果在该为为1，说明a和b的二进制在该为值不同
//    cout << "right_one: " << right_one << endl;
//    int a_or_b = 0;
//    for (int v : nums)
//    {
//        if (v == 6)
//        {
//            cout << "right_one & 6: " << (right_one & v) << endl;
//        }
//        if ((right_one & v) != 0)
//        {
//            cout << "v: " << v << endl;
//            a_or_b = a_or_b ^ v;
//        }
//    }
//    cout << "a的值为: " << a_or_b << endl;
//    int other_one = a_xor_b ^ a_or_b;
//    cout << "a的值为：" << a_or_b << "  b的值为: " << other_one << endl;
//}