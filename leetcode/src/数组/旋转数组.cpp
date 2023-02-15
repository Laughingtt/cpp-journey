//
// Created by tian on 2022/12/29.
//


/*输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2skh7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        // 使用取余的方式，让元素往后移动k位
        vector<int> temp(nums);
        for (int i = 0; i < temp.size(); ++i) {
                nums[(i+k)%nums.size()] = temp[i];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(nums, 3);

    for (int i = 0; i < nums.size(); ++i) {
        cout << " " << nums[i];
    }
    cout << endl;

}
