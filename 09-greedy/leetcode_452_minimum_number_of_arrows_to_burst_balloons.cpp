/**
 * LeetCode 452. 用最少数量的箭引爆气球
 * https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
 *
 * 题目：有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数
 *       数组 points，其中 points[i] = [xstart, xend] 表示水平直径在 xstart 和
 *       xend 之间的气球。弓箭一旦被射出之后，可以无限地前进。计算引爆所有气球
 *       所需的最小弓箭数。
 *
 * 思路：贪心，按右端点排序，重叠区间用一支箭，更新最小右边界
 *
 * 复杂度：时间复杂度 O(nlogn)，空间复杂度 O(log n)
 *         - 时间：sort 为 O(nlogn) 主导，单层 for 遍历 O(n)
 *         - 空间：sort 快排递归栈最坏 O(n)（随想录官方为最坏）、平均 O(logn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0452-minimum-number-of-arrows-to-burst-balloons.html
 *
 * 相关题目推荐：
 *   435. 无重叠区间
 *   56. 合并区间
 *   406. 根据身高重建队列
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

    int findMinArrowShots(vector<vector<int> > &points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), cmp);
        // 从 1 方便
        int res = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= points[i - 1][1]) {
                // min 而非 max，主管容易认为max让区间包囊更大，但是弓箭的位置是交集，所以要min
                points[i][1] = min(points[i - 1][1], points[i][1]);
            } else {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<vector<int> > points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << solution.findMinArrowShots(points1) << endl; // 期望输出 2

    // 示例 2
    vector<vector<int> > points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << solution.findMinArrowShots(points2) << endl; // 期望输出 4

    // 示例 3
    vector<vector<int> > points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << solution.findMinArrowShots(points3) << endl; // 期望输出 2

    return 0;
}
