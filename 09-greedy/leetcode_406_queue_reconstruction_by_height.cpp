/**
 * LeetCode 406. 根据身高重建队列
 * https://leetcode.cn/problems/queue-reconstruction-by-height/
 *
 * 题目：假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性
 *       （不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi，
 *       前面正好有 ki 个身高大于或等于 hi 的人。请你重新构造并返回输入数组
 *       people 所表示的队列。
 *
 * 思路：贪心，先按身高降序、k 升序排序，再按 k 插入位置
 *
 * 复杂度：时间复杂度 O(nlogn + n²)，空间复杂度 O(logn)（计入排序递归栈；不计则 O(1)）
 *         - 时间：sort 为 O(nlogn)，循环 n 次每次 vector erase+insert 为 O(n)，插入部分 O(n²)，
 *                 合计 O(nlogn + n²)，主导 O(n²)（原注释 O(n log n) 有误，漏算了插入开销）
 *         - 空间：sort 为 introsort，递归栈最坏 O(logn)；原地 erase/insert 仅 temp 一个常数
 *                 拷贝，故计入排序栈为 O(logn)，按惯例只算显式额外空间则为 O(1)
 *         （与代码随想录对比：时间一致为 O(nlogn + n²)；空间官网因新建 que 列为 O(n)，
 *           本代码复用入参数组原地操作，故更省）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0406-queue-reconstruction-by-height.html
 *
 * 相关题目推荐：
 *   TODO 链表优化
 *   452. 用最少数量的箭引爆气球
 *   56. 合并区间
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int> > reconstructQueue(vector<vector<int> > &people) {
        sort(people.begin(), people.end(), cmp);
        for (int i = 1; i < people.size(); i++) {
            int position = people[i][1];
            vector<int> temp = people[i];
            people.erase(people.begin() + i);
            people.insert(people.begin() + position, temp);
        }
        return people;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<vector<int> > people1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    for (const auto &p: solution.reconstructQueue(people1)) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;
    // 期望输出 [5,0] [7,0] [5,2] [6,1] [4,4] [7,1]

    // 示例 2
    vector<vector<int> > people2 = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    for (const auto &p: solution.reconstructQueue(people2)) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;
    // 期望输出 [4,0] [5,0] [2,2] [3,2] [1,4] [6,0]

    return 0;
}
