/**
 * LeetCode 77. 组合
 * https://leetcode.cn/problems/combinations/
 *
 * 题目：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 思路：回溯法，for 循环横向遍历 + 递归纵向深入，剪枝优化：剩余元素不足时提前终止）
 *
 * 复杂度：时间复杂度 O(k · C(n,k))（共 C(n,k) 个解，每个解拷贝路径 O(k)）
 *        空间复杂度 O(k)（path + 递归栈深度；不计输出结果）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0077-combinations.html
 *
 * 相关题目推荐：
 *   216. 组合总和 III
 *   39. 组合总和
 *   78. 子集
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > res;
vector<int> path;

class Solution {
public:
    void dfs(int n, int m, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // 可选剪枝优化 i <= n - k + path.size() + 1
        for (int i = m; i <= n; i++) {
            path.push_back(i);
            dfs(n, i + 1, k);
            path.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        res.clear();
        path.clear();
        dfs(n, 1, k);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    for (const auto &combo: solution.combine(4, 2)) {
        cout << "[" << combo[0] << "," << combo[1] << "] ";
    }
    cout << endl;
    // 期望输出 [1,2] [1,3] [1,4] [2,3] [2,4] [3,4]

    // 示例 2
    for (const auto &combo: solution.combine(1, 1)) {
        cout << "[" << combo[0] << "] ";
    }
    cout << endl;
    // 期望输出 [1]

    return 0;
}
