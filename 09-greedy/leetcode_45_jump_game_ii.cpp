/**
 * LeetCode 45. 跳跃游戏 II
 * https://leetcode.cn/problems/jump-game-ii/
 *
 * 题目：给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。每个元素
 *       nums[i] 表示从下标 i 向前跳转的最大长度。返回到达 nums[n-1] 的最小跳跃
 *       次数。生成的测试用例可以到达 nums[n-1]。
 *
 * 思路：贪心，记录当前覆盖范围与下一步最大覆盖范围，走到当前边界时步数 +1
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0045-jump-game-ii.html
 *
 * 相关题目推荐：
 *   55. 跳跃游戏
 *   1306. 跳跃游戏 III
 *   1340. 跳跃游戏 V
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int cover = 0;
        int ret = 0;
        int tempMax = 0;
        // 这个逻辑还好，还是好理解，基于跳跃I，核心就是cover。官网那个可以不考虑
        for (int i = 0; i <= cover; i++) {
            int temp = nums[i] + i;
            tempMax = max(temp, tempMax);
            if (cover >= nums.size() - 1) {
                break; // 因为力扣要求最后一定有ret，所以这里为了美观，还是退出到外面ret
            }
            // 下一步是这个范围内的最大步长，而不是最先较大步长
            if (i == cover) {
                cover = tempMax;
                tempMax = 0;
                ret++;
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << solution.jump(nums1) << endl; // 期望输出 2

    // 示例 2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << solution.jump(nums2) << endl; // 期望输出 2

    return 0;
}
