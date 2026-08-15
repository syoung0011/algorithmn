/**
 * LeetCode 707. 设计链表
 * https://leetcode.cn/problems/design-linked-list/
 *
 * 题目：设计链表的实现。可以选择单链表或双链表，实现：
 *       get(index)           获取链表中第 index 个节点的值
 *       addAtHead(val)       在链表第一个元素之前添加值为 val 的节点
 *       addAtTail(val)       将值为 val 的节点追加到链表末尾
 *       addAtIndex(index,val)在链表中的第 index 个节点之前添加值为 val 的节点
 *       deleteAtIndex(index) 如果索引 index 有效，则删除链表中的第 index 个节点
 *
 * 思路：虚拟头节点 + size 记录长度，注意边界判断
 *
 * 复杂度：略
 *
 * 参考：代码随想录-链表篇-设计链表
 *
 * 相关题目推荐：
 *   TODO 改用双向链表
 *   206. 反转链表
 *   146. LRU 缓存机制
 *   23. 合并 K 个升序链表
 */

#include <iostream>
#include "list_node.h"

using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {
        // 构造函数（初始化虚拟头节点与 size）
        _dummy=new ListNode();
        _size=0;
    }

    // ~MyLinkedList() {
    //     ListNode* cur = _dummy;
    //     while (cur) {   // 连带虚拟头节点一起，无需额外处理
    //         ListNode* temp = cur;
    //         cur = cur->next;
    //         delete temp;
    //         temp=nullptr;   // 其实只要最后一次temp置空
    //     }
    // }

    int get(int index) {
        // 获取指定索引的值
        if (index<0||index>_size-1)return -1;
        ListNode *cur=_dummy->next; // 直接用_dummy也行，但是就是繁一点。所以cur到底是上一个还是当前，要灵性判断
        while (index--) {
            cur=cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        // 头插
        ListNode* newNode=new ListNode(val);
        newNode->next=_dummy->next;
        _dummy->next=newNode;
        _size++;    // 别忘了
    }

    void addAtTail(int val) {
        // 尾插
        ListNode* newNode=new ListNode(val);
        ListNode* cur=_dummy;
        while (cur->next) {
            cur=cur->next;
        }
        cur->next=newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        // 指定索引（之前）插入
        if(index > _size) return;
        if(index < 0) index = 0;
        ListNode* newNode=new ListNode(val);
        ListNode* cur=_dummy;
        while (index--) {   // 不能用自实现的get，因为它是求值，可额外实现getNode，见下方
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        _size++;
    }

    // ListNode* getNode(int index) {
    //     ListNode* cur = _dummy->next;
    //     while (index--) cur = cur->next;
    //     return cur;
    // }

    void deleteAtIndex(int index) {
        // 指定索引删除
        if (index >= _size || index < 0) return;
        ListNode* cur=_dummy;
        while (index--) {
            cur=cur->next;
        }
        ListNode* temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        temp=nullptr;   // 习惯，回收置空，避免悬空指针再次使用
        _size--;
    }
private:
    ListNode* _dummy;
    int _size;
};

int main() {
    MyLinkedList linkedList;

    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);
    cout << linkedList.get(1) << endl;  // 期望输出 2
    linkedList.deleteAtIndex(1);
    cout << linkedList.get(1) << endl;  // 期望输出 3

    return 0;
}
