/**
 * LeetCode 90. 子集 II
 * https://leetcode.cn/problems/subsets-ii/
 *
 * 题目：给你一个整数数组 nums，其中可能包含重复元素，请你返回该数组所有可能的
 *       子集（幂集）。解集不能包含重复的子集。
 *
 * 思路：回溯法 + 排序，同层去重（used 数组或 set），每层递归开头收集结果
 *
 * 复杂度：时间复杂度 O(n · 2^n)（去重后解集个数 ∏(cnt_i+1) ≤ 2^n，每个解拷贝 path O(n)，
 *        故为 n 倍；排序另计 O(n log n)，被高阶项吸收）
 *        空间复杂度 O(n)（path + used + 递归栈深度；不计输出占的空间）
 *        若计入输出：O(n · 解集个数)，最坏 O(n · 2^n)
 *        注：与代码随想录口径一致（其标注即为 O(n * 2^n) / O(n)）；
 *        官网省略了「n 因子来自每个解拷贝 path」以及排序 O(n log n) 的说明，
 *        且未区分无重复时的 2^n 与有重复时 ∏(cnt_i+1) 的上界来源
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0090-subsets-ii.html
 *
 * 相关题目推荐：
 *   78. 子集
 *   491. 递增子序列
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > res;
vector<int> path;

class Solution {
public:
    void dfs(const vector<int> &nums, int index, vector<bool> &used) {
        res.push_back(path);
        // 其实不用担心这个，因为下面for的条件判断也是不满足的，所以可省
        if (index == nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, used);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 2, 2};
    for (const auto &sub: solution.subsetsWithDup(nums1)) {
        cout << "[";
        for (size_t i = 0; i < sub.size(); ++i) {
            cout << sub[i] << (i + 1 < sub.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [] [1] [1,2] [1,2,2] [2] [2,2]（顺序不限）

    // 示例 2
    vector<int> nums2 = {0};
    for (const auto &sub: solution.subsetsWithDup(nums2)) {
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
