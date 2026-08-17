/**
 * LeetCode 19. 删除链表的倒数第 N 个结点
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 *
 * 题目：给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 * 思路：双指针法，快指针先走 n+1 步，快慢指针同步前进
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录-链表篇-删除链表的倒数第 N 个结点
 *
 * 相关题目推荐：
 *   TODO 两趟扫描也可以，反正复杂度没变，可以尝试
 *   141. 环形链表
 *   876. 链表的中间结点
 *   21. 合并两个有序链表
 */

#include <iostream>
#include "list_node.h"

using namespace std;

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 即使传进来head，也可以自己在函数里面加dummy，简化逻辑，这样就不用判断head空之类的
        // 就算不用dummy，因相对位置不变，移动逻辑也不变。但是特殊情形判断逻辑很复杂，可以试试
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        // 因为快指针最终要指向null，而且要找到倒数第n个节点的前驱，所以要n+1
        n++;
        // &&fast可省去，因为题目限制不会有这种情况，也就是倒数第n个，这个n是合法的
        // 但是还是加上比较好，因为是逻辑上的保险，p=p->next就要求p非空
        while (n-- && fast) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        // 也能用temp->next，但我更喜欢下面用法，逻辑清晰
        slow->next = slow->next->next;
        delete temp;
        temp = nullptr;

        ListNode *res = dummy->next;
        delete dummy;
        dummy = nullptr;

        // 看似head也合理，因为就算空也和dummy->next同时
        // 但是值传递，dummy->next改变不代表head改变，因为函数内没有被重新赋值，head仍然指着原先头节点
        // 所以head有悬空风险，除非额外判断置空，但是复杂了
        // 所以返回dummy->next既是良好习惯也是代码需要
        return res; // 注意还有返回值
    }
};

int main() {
    Solution solution;

    // 示例 1
    ListNode *head1 = createList({1, 2, 3, 4, 5});
    ListNode *res1 = solution.removeNthFromEnd(head1, 2);
    printList(res1); // 期望输出 1->2->3->5->nullptr
    deleteList(res1);

    // 示例 2
    ListNode *head2 = createList({1});
    ListNode *res2 = solution.removeNthFromEnd(head2, 1);
    printList(res2); // 期望输出 nullptr
    deleteList(res2);

    // 示例 3
    ListNode *head3 = createList({1, 2});
    ListNode *res3 = solution.removeNthFromEnd(head3, 1);
    printList(res3); // 期望输出 1->nullptr
    deleteList(res3);

    return 0;
}
