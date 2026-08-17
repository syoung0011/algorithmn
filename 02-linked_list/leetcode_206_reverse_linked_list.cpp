/**
 * LeetCode 206. 反转链表
 * https://leetcode.cn/problems/reverse-linked-list/
 *
 * 题目：给你单链表的头节点 head，请你反转链表，并返回反转后的链表。
 *
 * 思路：双指针法，pre 与 cur 依次反转指针方向
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录-链表篇-反转链表
 *
 * 相关题目推荐：
 *   TODO 递归写法（其实就是双指针法提炼精简，但浪费空间。必须先会双指针法，不然递归极难理解）
 *   TODO 也可用头插法，没有答案，但是408学过
 *   92. 反转链表 II
 *   25. K 个一组翻转链表
 *   234. 回文链表
 */

#include <iostream>
#include "list_node.h"

using namespace std;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        // 思考为何不用dummy了
        // 为何pre必须初始化为空，这是难点1
        ListNode *pre = nullptr;
        ListNode *cur = head;
        // 这里就得用双指针pre和cur了。
        // 注：双指针并不非得是快慢指针，就是前后双指针
        // cur为空则退出，想想为什么用cur而不用pre，这是难点2
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main() {
    Solution solution;

    // 示例 1
    ListNode *head1 = createList({1, 2, 3, 4, 5});
    ListNode *res1 = solution.reverseList(head1);
    printList(res1); // 期望输出 5->4->3->2->1->nullptr
    deleteList(res1); // 反转后从新头节点释放整条链表

    // 示例 2
    ListNode *head2 = createList({1, 2});
    ListNode *res2 = solution.reverseList(head2);
    printList(res2); // 期望输出 2->1->nullptr
    deleteList(res2);

    // 示例 3
    ListNode *head3 = createList({});
    ListNode *res3 = solution.reverseList(head3);
    printList(res3); // 期望输出 nullptr
    deleteList(res3);

    return 0;
}
