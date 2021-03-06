188. 买卖股票的最佳时机 IV

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

思路：

dp[i]的值有两种可能：
第一，第i天完成第k笔买和卖，第k笔收益为0。
第二，第i天完成第k笔的卖出，之前的一些天完成其他交易。满足这种要求的所有情况，都能和第i-1天完成第k笔交易的情况建立一对一的关系，
只是第k笔交易的卖出价格由prices[i - 1]变为了prices[i]。所以dp[i] = dp[i - 1] - prices[i - 1] + prices[i]。

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int ans = 0;
        if (k >= n / 2) {
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1])
                    ans += prices[i] - prices[i - 1];
            }
            return ans;
        }
        vector<int> dp(n, 0);
        while (k-- > 0) {
            for (int i = 1; i < n; ++i)
                dp[i] = max(dp[i - 1] - prices[i - 1] + prices[i], dp[i]);
            for (int i = 1; i < n; ++i) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
        }
        return dp.back();
    }
};
