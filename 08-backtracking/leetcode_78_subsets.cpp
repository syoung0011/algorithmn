/**
 * LeetCode 78. 子集
 * https://leetcode.cn/problems/subsets/
 *
 * 题目：给你一个整数数组 nums，数组中的元素互不相同。返回该数组所有可能的子集
 *       （幂集）。解集不能包含重复的子集。可以按任意顺序返回解集。
 *
 * 思路：回溯法，收集路径的时机在每一层递归开头，而非叶子节点
 *
 * 复杂度：时间复杂度 O(?)，空间复杂度 O(?)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0078-subsets.html
 *
 * 相关题目推荐：
 *   90. 子集 II
 *   491. 递增子序列
 *   77. 组合
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;

class Solution {
public:
    void dfs(vector<int> &nums, int index) {
        res.push_back(path);
        if (index == nums.size()) return;
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        dfs(nums, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 2, 3};
    for (const auto& sub : solution.subsets(nums1)) {
        cout << "[";
        for (size_t i = 0; i < sub.size(); ++i) {
            cout << sub[i] << (i + 1 < sub.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [] [1] [2] [3] [1,2] [1,3] [2,3] [1,2,3]（顺序不限）

    // 示例 2
    vector<int> nums2 = {0};
    for (const auto& sub : solution.subsets(nums2)) {
        cout << "[";
        for (size_t i = 0; i < sub.size(); ++i) {
            cout << sub[i] << (i + 1 < sub.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [] [0]

    return 0;
}
