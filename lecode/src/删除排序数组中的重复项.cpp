//
// Created by tian on 2022/7/24.
//
#include "iostream"
#include "vector"

using namespace std;

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