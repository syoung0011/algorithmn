/**
 * LeetCode 56. 合并区间
 * https://leetcode.cn/problems/merge-intervals/
 *
 * 题目：以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] =
 *       [starti, endi]。请你合并所有重叠的区间，并返回一个不重叠的区间数组，
 *       该数组需恰好覆盖输入中的所有区间。
 *
 * 思路：贪心，按左端点排序，逐个合并重叠区间，更新右端点为较大值
 *
 * 复杂度：时间复杂度 O(nlogn)，空间复杂度 O(logn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0056-merge-intervals.html
 *
 * 相关题目推荐：
 *   57. 插入区间
 *   435. 无重叠区间
 *   452. 用最少数量的箭引爆气球
 *   763. 划分字母区间
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        vector<vector<int> > res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // 不是intervals[i-1]而是res，这太巧妙了
            if (intervals[i][0] <= res.back()[1]) {
                // 不用删了再重新添，直接等价改右边界就行
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<vector<int> > intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    for (const auto &interval: solution.merge(intervals1)) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    // 期望输出 [1,6] [8,10] [15,18]

    // 示例 2
    vector<vector<int> > intervals2 = {{1, 4}, {4, 5}};
    for (const auto &interval: solution.merge(intervals2)) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    // 期望输出 [1,5]

    return 0;
}
