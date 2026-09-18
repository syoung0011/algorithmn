/**
 * LeetCode 40. 组合总和 II
 * https://leetcode.cn/problems/combination-sum-ii/
 *
 * 题目：给定一个候选人编号的集合 candidates 和一个目标数 target，找出 candidates
 *       中所有可以使数字和为 target 的组合。candidates 中的每个数字在每个组合中
 *       只能使用一次。解集不能包含重复的组合。
 *
 * 思路：回溯法 + 排序，同层去重：candidates[i] ==
 *       candidates[i-1] 且 used[i-1] == false 时跳过
 *
 * 复杂度：时间复杂度 O(2^n · n)（递归树最坏 O(2^n) 个节点，每个解拷贝路径 O(n)；
 *        排序另计 O(n log n)。注意：官方题解即此口径，别漏掉「每个解的拷贝代价」）
 *        空间复杂度 O(n)（path + used + 递归栈深度；不计输出结果）
 *        若计入输出：O(n · 解的个数)，最坏 O(n · 2^n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0040-combination-sum-ii.html
 *
 * 相关题目推荐：
 *   39. 组合总和
 *   216. 组合总和 III
 *   90. 子集 II
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > res;
vector<int> path;
vector<bool> used;

class Solution {
public:
    void dfs(const vector<int> &candidates, int target, int idx) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            path.push_back(candidates[i]);
            used[i] = true;
            dfs(candidates, target - candidates[i], i + 1);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        res.clear();
        used.assign(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    for (const auto &combo: solution.combinationSum2(candidates1, 8)) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            cout << combo[i] << (i + 1 < combo.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [1,1,6] [1,2,5] [1,7] [2,6]

    // 示例 2
    vector<int> candidates2 = {2, 5, 2, 1, 2};
    for (const auto &combo: solution.combinationSum2(candidates2, 5)) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            cout << combo[i] << (i + 1 < combo.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [1,2,2] [5]

    return 0;
}
