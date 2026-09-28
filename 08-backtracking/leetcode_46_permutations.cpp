/**
 * LeetCode 46. 全排列
 * https://leetcode.cn/problems/permutations/
 *
 * 题目：给定一个不含重复数字的数组 nums，返回其所有可能的全排列。可以按任意
 *       顺序返回答案。
 *
 * 思路：回溯法，用 used 数组标记已选元素，排列元素
 *
 * 复杂度：时间 O(n·n!)（n! 个排列，每排列构造/拷贝代价 O(n)）；空间 O(n)（递归/辅助，不计返回结果）或 O(n·n!)（含返回的全部排列存储）。
 *          注：代码随想录记作 时间 O(n!)、空间 O(n)，未计每层 O(n) 拷贝与返回结果存储。
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0046-permutations.html
 *
 * 相关题目推荐：
 *   47. 全排列 II
 *   31. 下一个排列
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int> > res;

class Solution {
public:
    void dfs(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int> > permute(vector<int> &nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 2, 3};
    for (const auto &perm: solution.permute(nums1)) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i] << (i + 1 < perm.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1]

    // 示例 2
    vector<int> nums2 = {0, 1};
    for (const auto &perm: solution.permute(nums2)) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i] << (i + 1 < perm.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [0,1] [1,0]

    return 0;
}
