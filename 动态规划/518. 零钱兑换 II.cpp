518. 零钱兑换 II

给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

解法一：一维DP

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

解法二：二维DP

dp[i][j] : the number of combinations to make up amount j by using the first i types of coins
State transition:

not using the ith coin, only using the first i-1 coins to make up amount j, then we have dp[i-1][j] ways.
using the ith coin, since we can use unlimited same coin, 
we need to know how many ways to make up amount j - coins[i-1] by using first i coins(including ith), which is dp[i][j-coins[i-1]]

Initialization: dp[i][0] = 1

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][j]: 用i种硬币组成金额为j的数多少种方法
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] += dp[i - 1][j];
                if (j - coins[i - 1] >= 0) dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp.back().back();
    }
};
