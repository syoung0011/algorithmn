/**
 * LeetCode 435. 无重叠区间
 * https://leetcode.cn/problems/non-overlapping-intervals/
 *
 * 题目：给定一个区间的集合 intervals，其中 intervals[i] = [starti, endi]。
 *       返回需要移除区间的最小数量，使剩余区间互不重叠。
 *
 * 思路：贪心，按右端点排序，统计非交叉区间的数量，总数减去即为最少移除数
 *
 * 复杂度：时间复杂度 O(nlogn)，空间复杂度 O(logn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0435-non-overlapping-intervals.html
 *
 * 相关题目推荐：
 *   452. 用最少数量的箭引爆气球
 *   56. 合并区间
 *   763. 划分字母区间
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        // true 不交换，a在b之前
        return a[0] < b[0];
    }

    // 用erase，算法没问题，但是OJ超时，无法全a
    // 与正确方法有很多不同，res的初值及意义 i++位置，但核心算法是异曲同工
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     if (intervals.empty()) return 0;
    //     sort(intervals.begin(), intervals.end(), cmp);
    //     int res = 0;
    //     for (int i = 1; i < intervals.size();) {
    //         if (intervals[i][0] < intervals[i - 1][1]) {
    //             if (intervals[i][1] < intervals[i-1][1]) {
    //                 intervals.erase(intervals.begin() + i - 1);
    //             } else {
    //                 intervals.erase(intervals.begin() + i);
    //             }
    //             res++;
    //         } else {
    //             i++;
    //         }
    //     }
    //     return res;
    // }

    // 弓箭射气球，与弓箭数量的意义刚好相反，所以也能用 总数 - 弓箭数
    int eraseOverlapIntervals(vector<vector<int> > &intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        // 注意res的意义，这是关键
        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
                res++;
            }
            // 无else，理解算法
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<vector<int> > intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << solution.eraseOverlapIntervals(intervals1) << endl; // 期望输出 1

    // 示例 2
    vector<vector<int> > intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << solution.eraseOverlapIntervals(intervals2) << endl; // 期望输出 2

    // 示例 3
    vector<vector<int> > intervals3 = {{1, 2}, {2, 3}};
    cout << solution.eraseOverlapIntervals(intervals3) << endl; // 期望输出 0

    return 0;
}
