//
// Created by tian on 2022/11/13.
//

/*给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int left = 0;
        int max_profit = 0;
        for (int right = 1; right < prices.size(); ++right) {
            cout << "left right " << left << "  " << right << endl;
            if (prices[left] >= prices[right]) {
                left += 1;
                continue;
            } else {
                int diff = prices[right] - prices[left];
                cout << "diff " << diff << endl;
                max_profit += diff;
                left += 1;

            }
        }
        return max_profit;

    }
};

int main() {
//    vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {1, 2, 3, 4, 5};
    Solution s;
    int max_profit = s.maxProfit(prices);

    cout << "max_profit is " << max_profit << endl;

    return 0;
}