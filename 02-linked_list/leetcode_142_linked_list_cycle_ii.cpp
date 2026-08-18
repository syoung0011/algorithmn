/**
 * LeetCode 142. 环形链表 II
 * https://leetcode.cn/problems/linked-list-cycle-ii/
 *
 * 题目：给定一个链表的头节点 head，返回链表开始入环的第一个节点。
 *       如果链表无环，则返回 null。不允许修改给定的链表。
 *
 * 思路：快慢指针判断环，相遇后让指针从头部与相遇点同步走
 *
 * 复杂度：时间复杂度 O(n)（不是快指针位移而是循环次数，也就是慢指针位移），空间复杂度 O(1)
 *
 * 参考：代码随想录-链表篇-环形链表 II
 *
 * 相关题目推荐：
 *   141. 环形链表
 *   287. 寻找重复数
 *   876. 链表的中间结点
 */

#include <iostream>
#include "list_node.h"
#include <utility>  // 直接包含swap，iostream是间接
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        // 循环条件不一定非得聚合，因为循环体内可以用if来判断，而无需退出循环（繁）
        while (fast && fast->next) {
            // fast相对slow每次多移动一格，由于索引离散，如果有环，肯定会相遇，具体可看官网证明理解
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // 见官网证明，x=(n-1)(y+z)+z，所以从头和从相遇点出发，相遇点就是环入口
                // 这个代数很有初中数学题的味道了，为何要这么分解，而不是常人眼光下的n(y+z)-y
                // 用index1，2虽然物理上冗余（因为可以复用slow或fast，从而节省一个变量空间），但逻辑上清晰
                ListNode *index1 = head, *index2 = slow;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution solution;

    // 和力扣示例有点不同，力扣是pos也就是换入口索引，而下面是入口的值
    // 示例 1：环入口节点值为 2
    ListNode *head1 = createList({3, 2, 0, -4});
    ListNode *tail1 = head1;
    while (tail1->next) tail1 = tail1->next;
    tail1->next = head1->next; // 尾部连接到下标 1 的节点
    ListNode *result1 = solution.detectCycle(head1);
    cout << (result1 ? result1->val : -1) << endl; // 期望输出 2
    tail1->next = nullptr; // 先断开环，否则 deleteList 会无限循环
    deleteList(head1);

    // 示例 2：环入口节点值为 1
    ListNode *head2 = createList({1, 2});
    head2->next->next = head2; // 尾部连接到头节点
    ListNode *result2 = solution.detectCycle(head2);
    cout << (result2 ? result2->val : -1) << endl; // 期望输出 1
    head2->next->next = nullptr; // 断开环后释放
    deleteList(head2);

    // 示例 3：无环
    ListNode *head3 = createList({1});
    ListNode *result3 = solution.detectCycle(head3);
    cout << (result3 ? result3->val : -1) << endl; // 期望输出 -1
    deleteList(head3);

    return 0;
}
