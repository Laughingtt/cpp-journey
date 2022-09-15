#include "iostream"
#include "string"
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // 1. 比较
        string ss;
        for(char ch:s){
            if (isalnum(ch))
            {
                ss+=tolower(ch);
            }
        }
        // string a = ss;
        // reverse(ss.begin(),ss.end());
        // return a==ss;

        // 2. 双指针
        int left = 0;
        int right = ss.length()-1;
        
        while (left != right)
        {
            if (ss[left]==ss[right])
            {
                left++;
                right--;
            }else{
                return false;
            }
            
        }
        return true;
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string s("A man, a plan, a canal: sPanama");

    Solution pp = Solution();
    bool r = pp.isPalindrome(s);
    cout << r << endl;
    return 0;
}
