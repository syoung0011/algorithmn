/**
 * LeetCode 216. 组合总和 III
 * https://leetcode.cn/problems/combination-sum-iii/
 *
 * 题目：找出所有相加之和为 n 的 k 个数的组合，且满足：只使用数字 1 到 9；
 *       每个数字最多使用一次。返回所有可能的有效组合的列表，列表不能包含相同
 *       组合两次。
 *
 * 思路：回溯法，类似组合问题，增加和与剪枝条件
 *
 * 复杂度：时间复杂度 O(k · C(9,k))（候选只有 1~9 共 9 个数，递归树节点数受 k 层深度约束；
 *        每个解拷贝路径 O(k)）
 *        空间复杂度 O(k)（path + 递归栈深度；不计输出结果）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0216-combination-sum-iii.html
 *
 * 相关题目推荐：
 *   77. 组合
 *   39. 组合总和
 *   40. 组合总和 II
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > res;
vector<int> path;

class Solution {
public:
    // 用额外变量，而不是每次求和path，降低复杂度
    // sum其实可以省去，用 n - i ，为0时回溯
    void dfs(int k, int n, int m, int sum) {
        if (sum > n) return;
        if (path.size() == k) {
            if (sum == n) res.push_back(path);
            return;
        }
        for (int i = m; i <= 10 - k + path.size(); i++) {
            path.push_back(i);
            dfs(k, n, i + 1, sum + i);
            path.pop_back();
        }
    }

    vector<vector<int> > combinationSum3(int k, int n) {
        res.clear();
        path.clear();
        dfs(k, n, 1, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    for (const auto &combo: solution.combinationSum3(3, 7)) {
        cout << "[" << combo[0] << "," << combo[1] << "," << combo[2] << "] ";
    }
    cout << endl;
    // 期望输出 [1,2,4]

    // 示例 2
    for (const auto &combo: solution.combinationSum3(3, 9)) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            cout << combo[i] << (i + 1 < combo.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [1,2,6] [1,3,5] [2,3,4]

    return 0;
}
