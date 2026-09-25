/**
 * LeetCode 47. 全排列 II
 * https://leetcode.cn/problems/permutations-ii/
 *
 * 题目：给定一个可包含重复数字的序列 nums，按任意顺序返回所有不重复的全排列。
 *
 * 思路：回溯法 + 排序，used 数组既做树枝去重（已选），又做树层去重（同层跳过相同值）
 *
 * 复杂度：时间复杂度 O(?)，空间复杂度 O(?)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0047-permutations-ii.html
 *
 * 相关题目推荐：
 *   46. 全排列
 *   31. 下一个排列
 */

#include <algorithm>
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
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, used);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 1, 2};
    for (const auto &perm: solution.permuteUnique(nums1)) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i] << (i + 1 < perm.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [1,1,2] [1,2,1] [2,1,1]（顺序不限）

    // 示例 2
    vector<int> nums2 = {1, 2, 3};
    for (const auto &perm: solution.permuteUnique(nums2)) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i] << (i + 1 < perm.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 6 个排列

    return 0;
}
