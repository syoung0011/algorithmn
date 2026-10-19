/**
 * LeetCode 63. 不同路径 II
 * https://leetcode.cn/problems/unique-paths-ii/
 *
 * 题目：一个机器人位于一个 m x n 网格的左上角。网格中的障碍物和空位置分别用 1
 *       和 0 来表示。机器人每次只能向下或者向右移动一步。机器人试图达到网格的
 *       右下角。问总共有多少条不同的路径？障碍物处无法通行。
 *
 * 思路：动态规划，遇到障碍物 dp 置 0，初始化首行首列时注意障碍物之后全部为 0
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(mn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0063-unique-paths-ii.html
 *
 * 相关题目推荐：
 *   62. 不同路径
 *   64. 最小路径和
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        // 遍历初始化首行首列，要注意遇到障碍物即停，后继dp值为0，逻辑上模拟障碍，表示此路不通
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] != 1) {
                    // 不必判断 && obstacleGrid[i - 1][j] != 1，因为此处dp值就是0，加不加无所谓
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<vector<int> > grid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << solution.uniquePathsWithObstacles(grid1) << endl; // 期望输出 2

    // 示例 2
    vector<vector<int> > grid2 = {{0, 1}, {0, 0}};
    cout << solution.uniquePathsWithObstacles(grid2) << endl; // 期望输出 1

    return 0;
}
