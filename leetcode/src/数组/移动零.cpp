//
// Created by tian on 2022/12/29.
//


/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2ba4i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nums_res(nums.size(),0);
        int it=0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0){
                nums_res[it] = nums[i];
                ++it;
            }
        }
        copy(nums_res.begin(),nums_res.end(),nums.begin());
    }

    void moveZeroes2(vector<int>& nums) {
        // 双指针法
        // 1. 只需要遍历一次
        // 2. left 指向最左边的0, right指向数组值，right的值只要不是0，交换，left+=1
        int left=0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] !=0){
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                left+=1;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 0, 4, 0, 6, 7};
    s.moveZeroes2(nums);

    for (int i = 0; i < nums.size(); ++i) {
        cout << " " << nums[i];
    }
    cout << endl;

}

/*public void moveZeroes(int[] nums) {
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            //只要不为0就往前挪
            if (nums[j] != 0) {
                //i指向的值和j指向的值交换
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                i++;
            }
        }
    }

作者：数据结构和算法
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2ba4i/?discussion=AJ2rEF
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
