279. 完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

题解：

题解一：推荐

https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
dp[i] = the least number of perfect square numbers which sum to i. Note that dp[0] is 0.
For each i, it must be the sum of some number (i - j * j) and a perfect square number (j * j).

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp.back();
    }
};


题解二：

建立一个长度为 n+1 的一维dp数组，将第一个值初始化为0，其余值都初始化为 INT_MAX, 
i从0循环到n，j从1循环到 i+j*j <= n 的位置，然后每次更新 dp[i+j*j] 的值，动态更新 dp 数组，
其中 dp[i] 表示正整数i最少能由多个完全平方数组成，那么我们求n，就是返回 dp[n] 即可，也就是 dp 数组的最后一个数字。
需要注意的是这里的写法，i必须从0开始，j必须从1开始，因为我们的初衷是想用 dp[i] 来更新 dp[i + j * j]，
如果 i=0, j=1 了，那么 dp[i] 和 dp[i + j * j] 就相等了，怎么能用本身 dp 值加1来更新自身呢，参见代码如下：
    
class Solution {
public:
    int numSquares(int n) {
        int res;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    std::cout << s.numSquares(256) << std::endl;
    return 0;
}
