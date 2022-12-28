//
// Created by tian on 2022/12/22.
//

/*
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 */
#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int global_sub_length = INT32_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            int sub_length = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                sub_length += 1;
                if (sum >= target) {
                    global_sub_length = global_sub_length < sub_length ? global_sub_length : sub_length;
//                    cout << "global_sub_length " << global_sub_length <<endl;
                    break;
                }
            }
        }
        if (global_sub_length == INT32_MAX) {
            return 0;
        } else {
            return global_sub_length;
        }
    }

    int minSubArrayLen2(int target, vector<int> &nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= target) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    Solution s;

//    vector<int> nums = {2, 3, 1, 2, 4, 3};
//    vector<int> nums = {1,1,1,1,1,1,1,1};
    vector<int> nums = {1, 2, 3, 4, 5};
    int r = s.minSubArrayLen2(11, nums);

    std::cout << r << std::endl;
    return 0;
}