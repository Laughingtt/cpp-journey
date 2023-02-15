//
// Created by tian on 2022/12/29.
//


/*给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 

示例 1：

输入：nums = [1,2,3,1]
输出：true

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x248f5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {

        set<int> nums_set(nums.begin(), nums.end());
        if (nums_set.size() != nums.size()) {
            return true;
        } else {
            return false;
        }
    }

    bool containsDuplicate2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        auto r = std::unique(nums.begin(), nums.end());
        return (r != nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    bool r = s.containsDuplicate2(nums);

    cout << r << endl;
    cout << boolalpha << "r: " << r << endl;


    for (int i = 0; i < nums.size(); ++i) {
        cout << " " << nums[i];
    }
    cout << endl;

}
