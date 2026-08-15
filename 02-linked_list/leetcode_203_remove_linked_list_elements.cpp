/**
 * LeetCode 203. 移除链表元素
 * https://leetcode.cn/problems/remove-linked-list-elements/
 *
 * 题目：给你一个链表的头节点 head 和一个整数 val，请你删除链表中所有满足
 *       Node.val == val 的节点，并返回新的头节点。
 *
 * 思路：虚拟头节点统一处理头节点的删除逻辑
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录-链表篇-移除链表元素
 *
 * 相关题目推荐：
 *   27. 移除元素
 *   237. 删除链表中的节点
 *   83. 删除排序链表中的重复元素
 */

#include <iostream>
#include "list_node.h"

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(); // 用虚拟头节点简化代码，无需分类讨论
        dummy->next=head;   // 虚拟头节点!=头节点
        ListNode* cur=dummy;    // cur当前，这里是要判断节点的上一个，cur->next即可到达目标无需pre冗余指针
        while (cur->next) { // 不能写cur，不是多一次循环的问题，而是下面的if条件就会越界
            if (cur->next->val==val) {
                ListNode *temp=cur->next;
                cur->next=cur->next->next;  // 画图理解
                delete temp; // 必须最后删除，过早删除则cur->next直接丢失了
                temp=nullptr;
                //delete命令指示释放了temp指针原本所指的那部分内存，
                //被delete后的指针temp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
                //如果不再加上一句temp=nullptr,temp会成为乱指的野指针
                //如果之后的程序不小心使用了temp，会指向难以预想的内存空间
            }
            else {
                cur=cur->next;
            }
        }
        head=dummy->next;   // 重新赋值给head，这一步既是习惯，也必不可少，因为dummy空间需释放
        delete dummy;
        return head;
    }
};

int main() {
    Solution solution;

    // 示例 1
    ListNode* head1 = createList({1, 2, 6, 3, 4, 5, 6});
    printList(solution.removeElements(head1, 6));  // 期望输出 1->2->3->4->5->nullptr

    // 示例 2
    ListNode* head2 = createList({});
    printList(solution.removeElements(head2, 1));  // 期望输出 nullptr

    // 示例 3
    ListNode* head3 = createList({7, 7, 7, 7});
    printList(solution.removeElements(head3, 7));  // 期望输出 nullptr

    return 0;
}
