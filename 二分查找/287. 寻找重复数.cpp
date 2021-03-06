287. 寻找重复数

给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3

解题思路：

https://www.cnblogs.com/grandyang/p/4843654.html

这道题给了我们 n+1 个数，所有的数都在 [1, n] 区域内，首先让证明必定会有一个重复数，
类似小学华罗庚奥数中的抽屉原理(又叫鸽巢原理)，即如果有十个苹果放到九个抽屉里，
如果苹果全在抽屉里，则至少有一个抽屉里有两个苹果。

题目要求不能改变原数组，即不能给原数组排序，又不能用多余空间，那么哈希表也就不用考虑了，
又说时间小于 O(n^2)，也就不能用 brute force 的方法，那也就只能考虑用二分搜索法了。
在区间 [1, n] 中搜索，首先求出中点 mid，然后遍历整个数组，统计所有小于等于 mid 的数的个数。
如果个数小于等于 mid，则说明重复值在 [mid+1, n] 之间。反之，重复值应在 [1, mid-1] 之间。
然后依次类推，直到搜索完成，此时的 low 就是我们要求的重复值，参见代码如下：

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid) ++cnt;
            }
            if (cnt <= mid) left = mid + 1; // 说明在mid右边找，不包括mid
            else right = mid; //在mid左边找，包括mid
        }
        return left;
    }
};

