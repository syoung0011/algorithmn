/**
 * LeetCode 455. 分发饼干
 * https://leetcode.cn/problems/assign-cookies/
 *
 * 题目：假设你是一位很棒的家长，想要给你的孩子们一些小饼干。每个孩子最多只能
 *       给一块饼干。对每个孩子 i，都有一个胃口值 g[i]，饼干 j 的尺寸为 s[j]。
 *       若 s[j] >= g[i]，孩子 i 可以吃饱。目标是尽可能满足越多数量的孩子，
 *       并输出这个最大数值。
 *
 * 思路：贪心，先排序，小饼干优先满足小胃口的孩子；或大饼干优先满足大胃口的孩子
 *
 * 复杂度：时间复杂度 O(nlogn)，空间复杂度 O(1)
 *         - 时间：两次 sort 为 O(glogg + slogs)，线性扫描 O(s)，排序主导，整体 O(nlogn)
 *         - 空间：仅 slow、res 等常数变量，未开辟与规模相关的辅助空间，O(1)
 *         （与代码随想录一致：O(nlogn) / O(1)）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0455-assign-cookies.html
 *
 * 相关题目推荐：
 *   376. 摆动序列
 *   135. 分发糖果
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int slow = 0;
        int res = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            // 提前退出，官网是放在核心if里，那样会有冗余循环趟数
            if (slow == g.size()) break;
            if (s[fast] >= g[slow]) {
                res++;
                slow++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << solution.findContentChildren(g1, s1) << endl;  // 期望输出 1

    // 示例 2
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << solution.findContentChildren(g2, s2) << endl;  // 期望输出 2

    return 0;
}
