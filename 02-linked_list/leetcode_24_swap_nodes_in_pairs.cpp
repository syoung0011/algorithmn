/**
 * LeetCode 24. 两两交换链表中的节点
 * https://leetcode.cn/problems/swap-nodes-in-pairs/
 *
 * 题目：给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
 *       必须在不修改节点内部的值的情况下完成本题。
 *
 * 思路：虚拟头节点 + 三指针，循环处理每对节点
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录-链表篇-两两交换链表中的节点
 *
 * 相关题目推荐：
 *   TODO 改用递归（暂未了解，可能更难理解）
 *   25. K 个一组翻转链表
 *   206. 反转链表
 */

#include <iostream>
#include "list_node.h"

using namespace std;

class Solution {
public:
    // 以下两个方法有个小区别，前者要为下次循环的后置节点考虑，后者只考虑下次循环的前置节点
    // 1.自己想的方法，类似双指针，但可能情况比较复杂了，不好理解
    // ListNode *swapPairs(ListNode *head) {
    //     if (!head || !head->next) return head;
    //     ListNode *pre = head;
    //     ListNode *cur = head->next;
    //     ListNode *res = cur; // 仅用于记录返回头
    //     // 每趟循环的后置节点的next要提前连接下一次循环的后置节点
    //     // 因此循环条件不适合cur&&cur->next，缺少末尾最后一趟的处理
    //     // 这里用while 1然后循环体内自己做退出判断，是最为简便的
    //     while (1) {
    //         ListNode *temp = cur->next;
    //         cur->next = pre;
    //         // 合并了2个if，比较难理解，可以画图自己想一下
    //         if (!temp || !temp->next) {
    //             pre->next = temp;
    //             break;
    //         }
    //         pre->next = temp->next;
    //         pre = temp;
    //         cur = temp->next;
    //     }
    //     return res;
    // }

    // 2.官方题解，类似三指针吧，开头的指针不容易想到
    // 还是先画图，cur是三节点的1号节点，而实际要置换的是2号和3号
    // 置换结束后cur变为后来的3号，也就是原来的2号，中间隔一个向后遍历
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *cur = dummy;
        // 循环条件很巧妙，首先顺序不能掉，否则出错
        // 其次包含了奇数个节点情况，而无需再分情况，理解难度大幅降低
        while (cur->next && cur->next->next) {
            ListNode *temp = cur->next;
            ListNode *temp1 = cur->next->next->next;
            cur->next = cur->next->next;
            temp->next->next = temp;
            temp->next = temp1;
            cur = cur->next->next;
        }
        ListNode *res = dummy->next;
        delete dummy;
        dummy = nullptr;
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    ListNode *head1 = createList({1, 2, 3, 4});
    ListNode *res1 = solution.swapPairs(head1);
    printList(res1); // 期望输出 2->1->4->3->nullptr
    deleteList(res1);

    // 示例 2
    ListNode *head2 = createList({});
    ListNode *res2 = solution.swapPairs(head2);
    printList(res2); // 期望输出 nullptr
    deleteList(res2);

    // 示例 3
    ListNode *head3 = createList({1});
    ListNode *res3 = solution.swapPairs(head3);
    printList(res3); // 期望输出 1->nullptr
    deleteList(res3);

    return 0;
}
