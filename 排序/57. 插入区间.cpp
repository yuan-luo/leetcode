给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 

示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int flag = false;
        for (int i = 0; i < intervals.size(); ++i) {
            // case 1: 如果新区间的左界大于当前区间的右界，说明两个区间不相交，要把当前区间加进结果。
            if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
                continue;
            }
            // case 2: 如果新区间的右界小于当前区间的左界，说明两个区间不相交，要把当前区间及它后面的所有区间都加进结果。
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                flag = !flag;
                for (; i < intervals.size(); ++i) {
                    res.push_back(intervals[i]);
                }
                break;
            }
            // case 3: 合并区间 
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
 
        // 如果newInterval的区间比所有区间都大，那么这种情况newInterval不会在循环中加，需要在循环外加入。
        if (!flag) {
            res.push_back(newInterval);
        }

        return res;
    }
};
