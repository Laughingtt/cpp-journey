//
// Created by tian on 2022/12/26.
//


/*在一个由小写字母构成的字符串 s 中，包含由一些连续的相同字符所构成的分组。

例如，在字符串 s = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。

分组可以用区间 [start, end] 表示，其中 start 和 end 分别表示该分组的起始和终止位置的下标。上例中的 "xxxx" 分组用区间表示为 [3,6] 。

我们称所有包含大于或等于三个连续字符的分组为 较大分组 。

找到每一个 较大分组 的区间，按起始位置下标递增顺序排序后，返回结果。

输入：s = "abcdddeeeeaabbbcd"
输出：[[3,5],[6,9],[12,14]]
解释：较大分组为 "ddd", "eeee" 和 "bbb"

 */

#include "vector"
#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
//        cout << s << endl;
        int world_cont = 0;
        int start = 0;
        char current = s[0];
        for (int i = 0; i < s.size(); ++i) {
//            cout << s[i] << endl;
            if (s[i] == current) {
                world_cont += 1;
            } else {
                if (world_cont >= 3) {
                    vector<int> sub_res = {start};
                    sub_res.push_back(i - 1);
                    result.push_back(sub_res);
                }
                world_cont = 1;
                current = s[i];
                start = i;
            }

            if (i == s.size() - 1 and world_cont >= 3) {
                vector<int> sub_res = {start};
                sub_res.push_back(i);
                result.push_back(sub_res);
            }

        }
        return result;
    }
};


int main() {
    Solution s;

    string test = "abbxxxxzzy";
    string test2 = "abcdddeeeeaabbbcd";
    string test3 = "aaa";
    vector<vector<int>> result = s.largeGroupPositions(test2);
    cout << "result is " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << " " << result[i][j] << endl;
        }
    }
    return 0;
}