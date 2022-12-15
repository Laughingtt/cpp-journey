//
// Created by tian on 2022/7/24.
//
#include "iostream"
#include "vector"

using namespace std;


//给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0;
        for (int right = 1; right < nums.size(); ++right) {
            if (nums[left] == nums[right]) {
                continue;
            } else {
                // 右指针不等于左指针的时候，左指针+1,和右指针交换值
                left += 1;
                nums[left] = nums[right];
            }
        }
        return left + 1;
    }
};


int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution s;
    int leng = s.removeDuplicates(nums);
    std::cout << "长度为 " << leng << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
    }
    cout << "" << endl;

}