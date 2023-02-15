//
// Created by tian on 2022/12/29.
//


/*给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2y0c2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        // hash map 方式
        map<int, int> hash_map;
        vector<int> intersect_nums;
        for (int i = 0; i < nums1.size(); ++i) {
            if (hash_map.count(nums1[i]) == 0) {
                hash_map[nums1[i]] = 1;
            } else {
                hash_map[nums1[i]] = hash_map[nums1[i]] + 1;
            }
        }
        for (auto it: hash_map) {

            cout << it.first << " " << it.second << endl;
        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (hash_map.count(nums2[i]) > 0 && hash_map[nums2[i]] > 0) {
                intersect_nums.push_back(nums2[i]);
                hash_map[nums2[i]] -= 1;
            }
        }
        return intersect_nums;
    }


    vector<int> intersect_double_point(vector<int> &nums1, vector<int> &nums2) {
        // 双指针 方式
        // 1. 先排序
        // 2. i,j同时编译两个数组，遇到相同的元素压栈，向后+1，遇到不同的元素数字小的+1
        vector<int> intersect_nums;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

//        for (int i = 0; i < nums1.size(); ++i) {
//            cout << " " << nums1[i];
//        }
//        cout<< endl;
//
//        for (int i = 0; i < nums2.size(); ++i) {
//            cout << " " << nums2[i];
//        }

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i]==nums2[j]){
                intersect_nums.push_back(nums1[i]);
                ++i;
                ++j;
            }else{
                if (nums1[i]>nums2[j]){
                    ++j;
                }else{
                    ++i;
                }
            }
            cout << i << " " << j <<endl;
        }

        return intersect_nums;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
//    auto res = s.intersect(nums, nums2);
    auto res = s.intersect_double_point(nums, nums2);

    for (int i = 0; i < res.size(); ++i) {
        cout << " " << res[i];
    }
    cout << endl;

}
