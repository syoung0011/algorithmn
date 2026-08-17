#ifndef ALGORITHMN_LIST_NODE_H
#define ALGORITHMN_LIST_NODE_H

#include <iostream>
#include <vector>

// 链表节点定义（与 LeetCode / 代码随想录一致）
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 根据数组创建链表，如 [1,2,3] -> 1->2->3
inline ListNode* createList(const std::vector<int>& nums) {
    ListNode dummy; // 栈上虚拟头节点，函数结束自动释放，无需手动 delete
    ListNode* cur = &dummy;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy.next;
}

// 打印链表，如 1->2->3->nullptr；空链表输出 nullptr
inline void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        std::cout << cur->val << "->";  // 每个非空元素后无脑加箭头，因为最后肯定是nullptr兜底
        cur = cur->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 释放链表内存
inline void deleteList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif // ALGORITHMN_LIST_NODE_H
