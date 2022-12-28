//
// Created by tian on 2022/12/26.
//

/*
 * 有 n 个筹码。第 i 个筹码的位置是 position[i] 。

我们需要把所有筹码移到同一个位置。在一步中，我们可以将第 i 个筹码的位置从 position[i] 改变为:

position[i] + 2 或 position[i] - 2 ，此时 cost = 0
position[i] + 1 或 position[i] - 1 ，此时 cost = 1
返回将所有筹码移动到同一位置上所需要的 最小代价
输入：position = [2,2,2,3,3]
输出：2
解释：我们可以把位置3的两个筹码移到位置2。每一步的成本为1。总成本= 2。

 */
#include "vector"
#include "iostream"
#include "math.h"

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int> &position) {
        int odd = 0;
        int even = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2) {
                odd += 1;
            } else {
                even += 1;
            }
        }
        return min(odd, even);

    }
};

int main() {

    Solution s;
    vector<int> position = {2, 2, 2, 3, 3};
    vector<int> position2 = {1, 10000000};
    vector<int> position3 = {1, 2, 3};
    int r = s.minCostToMoveChips(position3);
    cout << "r is " << r << endl;
    return 0;
}