#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int s = nums.size();
        int mx1 = max(nums[0], nums[1]);
        int mx2 = min(nums[0], nums[1]);
        int le1 = max(nums[0], nums[1]);
        int le2 = min(nums[0], nums[1]);

        for (size_t i = 2; i < s; i++)
        {
            int current = nums[i];
            if (current > mx1)
            {
                mx2 = mx1;
                mx1 = current;
            }
            else if (current > mx2)
            {
                mx2 = current;
            }
            if (current < le2)
            {
                le1 = le2;
                le2 = current;
            }
            else if (current < le1)
            {
                le1 = current;
            }
        }
        return (mx1 * mx2) - (le2 * le1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();

     vector<int> nums = {5, 6, 2, 7, 4};
//    vector<int> nums = {8,3,5,7};

    int res = s.singleNumber(nums);
    cout << res << endl;

    return 0;
}
