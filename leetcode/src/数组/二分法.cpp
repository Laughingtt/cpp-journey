//
// Created by tian on 2022/12/15.
//
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。



#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int binary_search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left; // 得到中间索引值
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else{
                return nums[mid];
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();

    vector<int> nums = {1, 4, 5, 6, 11, 33, 223, 1234};
    int target = 123;

    int res = s.binary_search(nums, target);

    cout << res << endl;

    return 0;
}
