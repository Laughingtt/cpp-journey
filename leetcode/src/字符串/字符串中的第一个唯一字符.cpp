//
// Created by tian on 2022/12/30.
//

#include "iostream"
#include "string"
#include "algorithm"
#include "map"
/*给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

 

示例 1：

输入: s = "leetcode"
输出: 0
示例 2:

输入: s = "loveleetcode"
输出: 2

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/xn5z8r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> char_map;
        for (int i = 0; i < s.size(); ++i) {
            if (char_map.count(s[i]) == 0) {
                char_map[s[i]] = 1;
            } else {
                char_map[s[i]] = char_map[s[i]] + 1;
            }
        }
//        for (auto it: char_map) {
//            cout << it.first << " : " << it.second << " ";
//        }
        cout << endl;
        for (int i = 0; i < s.size(); ++i) {
            if (char_map[s[i]] == 1) {
                return i;
            }
        }
        return -1;

    }
};

int main() {
    Solution s;

    string str = "loveleetcode";
    int res = s.firstUniqChar(str);
    cout << res << endl;

    return 0;
}