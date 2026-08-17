/**
 * LeetCode 面试题 02.07. 链表相交
 * https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 *
 * 题目：给你两个单链表的头节点 headA 和 headB，请你找出并返回两个单链表相交的
 *       起始节点。如果两个链表没有交点，返回 null。相交指的是节点引用相同。
 *
 * 思路：先求两链表长度差，长链表指针先走，再同步比较
 *
 * 复杂度：时间复杂度 O(n+m)，空间复杂度 O(1)
 *
 * 参考：代码随想录-链表篇-链表相交
 *
 * 相关题目推荐：
 *   160. 相交链表
 *   141. 环形链表
 *   142. 环形链表 II
 */

#include <iostream>
#include "list_node.h"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        // 先分别统计长度
        while (curA) {
            lenA++;
            curA = curA->next; // 易忘，勿遗漏
        }
        while (curB) {
            lenB++;
            curB = curB->next;
        }
        // 重置
        curA = headA;
        curB = headB;
        // 让A为较长链表，简化代码逻辑
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        // 对齐起点
        while (gap--) {
            curA = curA->next;
        }
        // 这里curA&&和curB&&没区别，因为已经对齐了，就算B为null，A也移到末尾null了
        // 包含了有空的情形，无需特殊判断
        while (curA && curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        return curB;
    }
};

int main() {
    Solution solution;

    // 示例 1：相交节点值为 8，位于 A 的第 2 个节点、B 的第 3 个节点
    ListNode *common = createList({8, 4, 5});
    ListNode *headA = createList({4, 1});
    ListNode *headB = createList({5, 0, 1});
    ListNode *tailA = headA;
    ListNode *tailB = headB;
    while (tailA->next) tailA = tailA->next;
    while (tailB->next) tailB = tailB->next;
    tailA->next = common;
    tailB->next = common;
    ListNode *result = solution.getIntersectionNode(headA, headB);
    cout << (result ? result->val : -1) << endl; // 期望输出 8
    // 释放：先断开与公共部分的连接，分别释放各自前缀，公共部分只释放一次
    tailA->next = nullptr;
    tailB->next = nullptr;
    deleteList(headA);
    deleteList(headB);
    deleteList(common);

    // 示例 2：不相交
    ListNode *headC = createList({2, 6, 4});
    ListNode *headD = createList({1, 5});
    ListNode *result2 = solution.getIntersectionNode(headC, headD);
    cout << (result2 ? result2->val : -1) << endl; // 期望输出 -1
    deleteList(headC);
    deleteList(headD);

    return 0;
}
