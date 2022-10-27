//
// Created by tian on 2022/10/19.
//

//给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）
// 定理： a,b 两个整数，(a,b) 为最大公约数，[a,b]为最小公倍数 ,所以(a,b)x[a,b]=ab(a,b均为整数)
// 此题为2和n的最小公倍数，如果n为奇数互质，所以最小公倍数为2*n,反之为n;
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n % 2 == 0) ? n : n * 2;
    }
};

#include "iostream"

int main() {
    Solution s;
    int r = s.smallestEvenMultiple(10);
    std::cout << "r is " << r << std::endl;
    return 0;
}