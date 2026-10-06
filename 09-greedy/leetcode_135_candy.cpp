/**
 * LeetCode 135. 分发糖果
 * https://leetcode.cn/problems/candy/
 *
 * 题目：n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。你需要
 *       按照以下要求，给这些孩子分发糖果：每个孩子至少分配到 1 个糖果；
 *       相邻两个孩子评分更高的孩子会获得更多的糖果。请你给每个孩子分发糖果，
 *       计算并返回需要准备的最少糖果数目。
 *
 * 思路：贪心，两次遍历：从左到右保证右边高分多得，再从右到左保证左边高分多得，取两次较大值）
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0135-candy.html
 *
 * 相关题目推荐：
 *   455. 分发饼干
 *   134. 加油站
 *   239. 滑动窗口最大值
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(), 1);
        // 单向，而不是双向一起，不然复杂度会很高
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        int sum = candy[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                // max是精髓，因为上一次单向确实会有一些问题
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
            // 这里省一个循环
            sum += candy[i];
        }
        return sum;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> ratings1 = {1, 0, 2};
    cout << solution.candy(ratings1) << endl; // 期望输出 5

    // 示例 2
    vector<int> ratings2 = {1, 2, 2};
    cout << solution.candy(ratings2) << endl; // 期望输出 4

    return 0;
}
