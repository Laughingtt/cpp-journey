//
// Created by tian on 2022/10/19.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> rs;
        for (int i = 0; i < nums.size(); i++)
        {
            rs.push_back(nums[nums[i]]);
        }
        return rs;
    }
};

int main(){
    vector<int> num = {0,2,1,5,3,4};
    Solution s;
    vector<int>r = s.buildArray(num);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }

}