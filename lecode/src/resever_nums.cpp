#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(nums[i]);
            res.push_back(nums[n+i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();

    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    vector<int> res = s.shuffle(nums, n);

    for (auto const &value : res)
    {
        cout << value << endl;
    }

    return 0;
}
