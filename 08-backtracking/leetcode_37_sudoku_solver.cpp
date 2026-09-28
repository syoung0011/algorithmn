/**
 * LeetCode 37. 解数独
 * https://leetcode.cn/problems/sudoku-solver/
 *
 * 题目：编写一个程序，通过填充空格来解决数独问题。数独的解法需遵循如下规则：
 *       数字 1-9 在每一行只能出现一次；数字 1-9 在每一列只能出现一次；
 *       数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 *       空格用 '.' 表示，原地修改棋盘。
 *
 * 思路：回溯法，双重循环找空格，尝试 1-9 并校验行列与九宫格合法性；返回 bool 的二维递归
 *
 * 复杂度：时间复杂度 O(9^m)，m 为空格数量（最坏 m=81，退化为 O(9^81) 的极端上界）；
 *         每个搜索节点需 O(9) 做行列与九宫格校验（常数级），故严格写作 O(9^m · 9)，
 *         同一量级，惯常记为 O(9^m)。
 *         空间复杂度 O(m)，即递归栈深度（最多 m 层），棋盘为原地修改不额外占空间。
 *         注：代码随想录该页未给出专门复杂度分析，正文仅粗略提到"最坏 9^9"，
 *             属对初盘空格数的放大上界，与本处 O(9^m) 同阶、不冲突。
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0037-sudoku-solver.html
 *
 * 相关题目推荐：
 *   51. N 皇后
 *   36. 有效的 数独
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(int row, int col, char val, vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == val) return false;
        }
        for (int j = 0; j < board.size(); j++) {
            if (board[row][j] == val) return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == val) return false;
            }
        }
        return true;
    }

    // 不传递坐标，从头扫描
    // 不和n皇后那样，一行只放一个，只需要一个循环确定列
    // 而数独要确定放的位置就要二重循环确定坐标，然后再需一个循环确定数字，而皇后只需无脑放Q
    bool dfs(vector<vector<char> > &board) {
        // 尽管是二维数组，但它仍是某种类型的一维数组，board size依然可以用
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') continue;
                // 不用int，直接用char
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        // 不能直接return dfs，就相当于只测验了一个情形
                        if (dfs(board)) return true;
                        board[i][j] = '.';
                    }
                }
                // 本轮无数可填，回溯
                return false;
            }
        }
        // 填满数独的最终答案
        return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
        dfs(board);
    }
};

int main() {
    Solution solution;

    // 示例
    vector<vector<char> > board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solution.solveSudoku(board);
    for (const auto &row: board) {
        for (char c: row) {
            cout << c << " ";
        }
        cout << endl;
    }
    // 期望输出完整的解数独结果

    return 0;
}
