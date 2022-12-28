//
// Created by tian on 2022/12/15.
//
// 题目:
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
// 示例1
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//输入：nums = [0,1,2,2,3,0,4,2], val = 2
//输出：5, nums = [0,1,4,0,3]
//解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。

// 示例2
//输入：nums = [3,2,2,3], val = 3
//输出：2, nums = [2,2]
//解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
//例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int remove_val(vector<int> &nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            while (left <= right) {
                if (nums[right] == val) {
                    right -= 1;
                } else {
                    break;
                }
            }
            while (left <= right) {
                if (nums[left] == val) {
                    break;
                } else {
                    left += 1;
                }
            }
            if (left < right) {
                nums[left] = nums[right];
                nums[right] = val;
            }

        }

//        for (int i = 0; i < nums.size(); ++i) {
//            cout << " " << nums[i];
//
//        }
//        cout << "" << endl;
//        cout << "left " << left << endl;
//        cout << "right " << right << endl;

        if (left<=right){
            return left;
        } else{
            return right;
        }

//        return left;

    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();

//    vector<int> nums = {1, 4, 5, 6, 11, 4, 1, 4};
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
//    vector<int> nums = {3,2,2,3};
//    vector<int> nums = {1};
    int target = 2;

    int res = s.remove_val(nums, target);

    cout << "res" << res << endl;

    return 0;
}
