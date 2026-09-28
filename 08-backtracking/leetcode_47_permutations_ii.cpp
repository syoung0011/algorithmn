/**
 * LeetCode 47. 全排列 II
 * https://leetcode.cn/problems/permutations-ii/
 *
 * 题目：给定一个可包含重复数字的序列 nums，按任意顺序返回所有不重复的全排列。
 *
 * 思路：回溯法 + 排序，used 数组既做树枝去重（已选），又做树层去重（同层跳过相同值）
 *
 * 复杂度：时间复杂度 O(n! * n)，空间复杂度 O(n)
 *   自行分析：最差情况（元素全唯一）叶子共 n! 个，每个叶子拷贝长度 n 的 path 入 res，
 *             代价 O(n) → O(n! * n)；排序 O(n log n) 可忽略；空间为递归深度 O(n)
 *             （path/used/栈），不计返回值 → O(n)。去重不增渐进量级，仅减常数因子。
 *   官网对比：代码随想录同样写 O(n! * n)、O(n)，与本文分析完全一致，无差距。
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
