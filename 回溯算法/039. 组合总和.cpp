39. 组合总和

给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

示例 1：
输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]

示例 2：
输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

题解注意事项：

千万要注意这道题和77题求组合的区别。这道题的数字可以重复，所以在迭代的时候输入参数depth为i，而不是i+1。已经犯过两次错误。不能犯第三次。

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        if (candidates.empty()) return ans;
        sort(candidates.begin(), candidates.end());
        helper(ans, out, candidates, 0, target);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& out,vector<int>& candidates, int depth, int target) {
        if (target == 0) {
            ans.push_back(out);
            return;
        }
        for (int i = depth; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                out.push_back(candidates[i]);
                helper(ans, out, candidates, i, target - candidates[i]); // 特别注意这道题的depth继续为i，因为迭代的时候每个数组可以重复，所以要重复计算。
                out.pop_back();                
            }
        }
    }
};
