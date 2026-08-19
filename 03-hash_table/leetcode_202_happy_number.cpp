/**
 * LeetCode 202. 快乐数
 * https://leetcode.cn/problems/happy-number/
 *
 * 题目：编写一个算法来判断一个数 n 是不是快乐数。快乐数定义为：
 *       对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
 *       然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。
 *       如果可以变为 1，那么这个数就是快乐数。
 *
 * 思路：哈希集合记录出现过的数，检测循环；或快慢指针
 *
 * 复杂度：时间复杂度 O(log n)，空间复杂度 O(log n)（哈希集合记录出现过的平方和；int 范围内首次计算后数值 ≤ 810，迭代次数有常数上界）
 * 复杂度具体分析见本节笔记
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0202-happy-number.html
 *
 * 相关题目推荐：
 *   141. 环形链表
 *   258. 各位相加
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n){
        int sum=0;
        //
        while (n) {
            int num=n%10;
            sum+=num*num;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> sum_set;
        // 不必纠结循环条件设置，内部判断退出就行
        while (1) {
            // 抽离成函数更清晰
            int sum=getSum(n);
            if (sum==1)return true;
            if (sum_set.find(sum)!=sum_set.end()) {
                return false;
            } else {
                // 此处可省else，但是更合逻辑
                sum_set.insert(sum);
            }
            n=sum;
        }
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << (solution.isHappy(19) ? "true" : "false") << endl;  // 期望输出 true
    // 19 -> 82 -> 68 -> 100 -> 1

    // 示例 2
    cout << (solution.isHappy(2) ? "true" : "false") << endl;  // 期望输出 false

    return 0;
}
