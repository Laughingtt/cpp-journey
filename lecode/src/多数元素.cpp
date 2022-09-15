#include "iostream"
#include "map"
#include "vector"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> dic;
        for (int i : nums)
        {
            if (dic.count(i) == 0)
            {
                dic[i] = 1;
            }
            else
            {
                dic[i]++;
            }
            if (dic[i]>nums.size()/2){
                return i;
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 2, 3,2,2,2};
    Solution s;
    int r = s.majorityElement(nums);
    cout << r << endl;
    return 0;
}
