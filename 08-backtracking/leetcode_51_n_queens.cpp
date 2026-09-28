/**
 * LeetCode 51. N 皇后
 * https://leetcode.cn/problems/n-queens/
 *
 * 题目：按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的
 *       棋子。n 皇后问题研究的是如何将 n 个皇后放置在 n x n 的棋盘上，并且使
 *       皇后彼此之间不能相互攻击。返回所有不同的 n 皇后问题的解决方案。
 *
 * 思路：回溯法，每行放置一个皇后，用列/主对角/副对角，标记冲突；或逐格校验是否与已放置皇后冲突
 *
 * 复杂度：时间复杂度 O(n * n!)，空间复杂度 O(n^2)
 *   自行分析：递归树约 n! 个节点（每行至多 n 分支、受剪枝），每个节点 isValid 遍历
 *             列/两个斜线共 O(n) → 时间 O(n * n!)；空间含棋盘 O(n^2)，递归栈 O(n)
 *             → 取 O(n^2)。（仅统计答案数会是 n!，但本实现需显式建棋盘并校验）
 *   官网对比：代码随想录写 O(n!)、O(n)。差距：①时间它只数叶子/方案数，略去每节点
 *             O(n) 的 isValid 校验；②空间它只算递归深度 O(n)，未计 O(n^2) 棋盘。
 *             二者同为"回溯模板"级粗略结论，本文更精确，渐进量级一致。
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0051-n-queens.html
 *
 * 相关题目推荐：
 *   37. 解数独
 *   36. 有效的数独
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string> > res;

class Solution {
public:
    bool isValid(vector<string> &board, int row, int col, int n) {
        // 不用担心当前已经是Q，因为这不可能，每层都是顺序遍历，初始都是无Q
        // 因此无需检验行
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // 因为是逐层，所以每次只要检查左上右上两个方向，而不包括下面
        // for的判断自动提前退出，不要在里面if，不然就有冗余遍历
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<string> &board, int n, int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            // 不是合法才dfs，而是合法才添加+dfs
            if (isValid(board, row, i, n)) {
                board[row][i] = 'Q';
                dfs(board, n, row + 1);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        res.clear();
        // 这个初始化需要熟悉，string 不能写成 vector<char>
        vector<string> board(n, string(n, '.'));
        dfs(board, n, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    for (const auto &board: solution.solveNQueens(4)) {
        for (const string &row: board) {
            cout << row << endl;
        }
        cout << "---" << endl;
    }
    // 期望输出两种解法：
    // .Q.. / ...Q / Q... / ..Q.
    // ..Q. / Q... / ...Q / .Q..

    // 示例 2
    for (const auto &board: solution.solveNQueens(1)) {
        for (const string &row: board) {
            cout << row << endl; // 期望输出 Q
        }
    }

    return 0;
}
