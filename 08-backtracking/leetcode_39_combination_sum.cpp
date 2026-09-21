/**
 * LeetCode 39. 组合总和
 * https://leetcode.cn/problems/combination-sum/
 *
 * 题目：给你一个无重复元素的整数数组 candidates 和一个目标整数 target，找出
 *       candidates 中可以使数字和为目标数 target 的所有不同组合，并以列表形式
 *       返回。candidates 中的同一个数字可以无限制重复被选取。
 *
 * 思路：回溯法，同层元素可重复选，startIndex 不 +1；排序 + 剪枝优化
 *
 * 复杂度：时间复杂度 O(n^(target/min(candidates)))（n 为候选数，递归深度受 target/min 约束，
 *        即「最多能取几个数」；每个解还要拷贝 O(target/min) 长度。
 *        这是指数级上界，实际受 target 限制远小于它）
 *       空间复杂度 O(target/min(candidates))（path + 递归栈深度；不计输出结果）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0039-combination-sum.html
 *
 * 相关题目推荐：
 *   40. 组合总和 II
 *   216. 组合总和 III
 *   77. 组合
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int> > res;

class Solution {
public:
    void dfs(int idx, int sum, const vector<int> &candidates, int target) {
        // 竖向剪枝
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }
        // 可以先排序原数组，再进入算法，这样就可以横向剪枝
        for (int i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(i, sum + candidates[i], candidates, target);
            path.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        res.clear();
        path.clear();
        dfs(0, 0, candidates, target);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> candidates1 = {2, 3, 6, 7};
    for (const auto &combo: solution.combinationSum(candidates1, 7)) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            cout << combo[i] << (i + 1 < combo.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [2,2,3] [7]

    // 示例 2
    vector<int> candidates2 = {2, 3, 5};
    for (const auto &combo: solution.combinationSum(candidates2, 8)) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            cout << combo[i] << (i + 1 < combo.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [2,2,2,2] [2,3,3] [3,5]

    return 0;
}
