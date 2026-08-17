/**
 * LeetCode 59. 螺旋矩阵 II
 * https://leetcode.cn/problems/spiral-matrix-ii/
 *
 * 题目：给你一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序
 *       螺旋排列的 n x n 正方形矩阵 matrix。
 *
 * 思路：循环不变量，坚持左闭右开区间，逐层填充四边
 *
 * 复杂度：时间复杂度 O(n^2)，空间复杂度 O(1)
 *
 * 参考：代码随想录-数组篇-螺旋矩阵 II
 *
 * 相关题目推荐：
 *   54. 螺旋矩阵
 *   48. 旋转图像
 *   885. 螺旋矩阵 III
 *   LCR 146. 螺旋遍历二维数组
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int startx = 0, starty = 0;
        vector<vector<int> > res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        // 大大方方新建变量，方便自己，而不是用x,y的代数式间接表示，offset同理
        int loop = n >> 1;
        int offset = 1;
        int count = 1;
        while (loop--) {
            int i = startx;
            int j = starty;
            for (; j < n - offset; j++) {
                res[i][j] = count++;
            }
            for (; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > starty; j--) {
                // 这里其实也能用offset，只是y现成
                res[i][j] = count++;
            }
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if (n & 1) {
            res[startx][starty] = count; // 处理中间单个元素，n为偶数则无需
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<vector<int> > result1 = solution.generateMatrix(3);
    for (const auto &row: result1) {
        for (int num: row) {
            cout << num << " ";
        }
        cout << endl;
    }
    // 期望输出：
    // 1 2 3
    // 8 9 4
    // 7 6 5

    // 示例 2
    vector<vector<int> > result2 = solution.generateMatrix(1);
    for (const auto &row: result2) {
        for (int num: row) {
            cout << num << " ";
        }
        cout << endl;
    }
    // 期望输出：1

    return 0;
}
