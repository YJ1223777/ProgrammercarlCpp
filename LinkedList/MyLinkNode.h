//
// Created by YJ_1223 on 2024/1/18.
//

#ifndef PROGRAMMERCARL_MYLINKNODE_H
#define PROGRAMMERCARL_MYLINKNODE_H

#include <iostream>
#include <vector>

using namespace std;

// 单链表
struct LinkNode
{
    int val;
    LinkNode* next;
    // 自定义构造函数
//    LinkNode(int x) : val(x), next(NULL){}
};

class Solution{
public:

    /**
     * 创建一个链表 默认从0开始依次增加1
     * @param n 链表的长度
     * @return 链表的头节点
     */
    LinkNode* creatList(int n) {
        LinkNode* Head=new LinkNode; //头节点
        Head->val = 0;
        Head->next = nullptr;
        LinkNode* pre = Head;  //指向下一个节点的过渡值
        for (int i=1;i<n;i++) {
            LinkNode* temp = new LinkNode;
            temp->val = i;
            pre->next = temp;
            pre = temp;
            temp->next = nullptr;
        }
        return Head;
    }

    /**
     * 展示链表的所有元素
     * @param head 头节点
     */
    void showList(LinkNode* head) {
        LinkNode* temp=head;
        int val;
        cout << "LinkList: ";
        while (temp!=nullptr) {
            val = temp->val;
            cout << val << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    /**
     * 移除元素 直接使用原来的链表进行操作
     * @param head 头节点
     * @param target 需要移除的元素
     * @return 处理后的链表的头节点
     */
    LinkNode* removeElement(LinkNode* head, int target) {
        while (head != nullptr && head->val == target) {
            LinkNode* cur = head;
            head = head -> next;
            delete cur;
        }
        LinkNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if(temp->next->val == target) {
                LinkNode* cur = temp->next ;
                temp->next = temp->next->next;
                delete cur;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }

    /**
     * 移除元素 使用虚拟头节点
     * @param head 头节点
     * @param target 需要移除的元素
     * @return 处理后的链表的头节点
     */
    LinkNode* removeElementWithDumHead(LinkNode* head, int target) {
        LinkNode *dummyHead = new LinkNode; // 创建虚拟头节点
        dummyHead->val = INT_MIN;
        dummyHead->next = head;
        LinkNode* temp = dummyHead;
        while (temp->next != nullptr) {
            if(temp->next->val == target) {
                LinkNode* cur = temp->next ;
                temp->next = temp->next->next;
                delete cur;
            } else {
                temp = temp->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }

    /**
     * 获取链表中第 index 个节点的值。如果索引无效，则返回-1。
     * @param head 链表的头节点
     * @param index 索引
     * @return 索引值
     */
    int getIndex(LinkNode* head, int index) {
        int cnt = 0;
        LinkNode* tmp = head;
        while (tmp != nullptr) {
            if(cnt == index) {
                return tmp->val;
            }
            tmp = tmp->next;
            cnt++;
        }
        return -1;
    }

    /**
     * 在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
     * @param head 原链表的头节点
     * @param val 添加的值
     * @return 新链表的头节点
     */
    LinkNode* addAtHead(LinkNode* head, int val) {
        LinkNode* newHead = new LinkNode;
        newHead->next = head;
        newHead->val = val;
        return newHead;
    }

    /**
     * 将值为 val 的节点追加到链表的最后一个元素。
     * @param head 原链表的头节点
     * @param val 追加的值
     * @return 新链表的头节点
     */
    LinkNode* addAtTail(LinkNode* head, int val) {
        LinkNode* temp = head;
        while (temp != nullptr) {
            if(temp->next == nullptr) {
                LinkNode* newTail = new LinkNode;
                temp->next = newTail;
                newTail->next = nullptr;
                newTail->val = val;
                break;
            }
            temp = temp->next;
        }
        return head;
    }

    /**
     * 在链表中的第 index个节点之前添加值为val的节点
     * @param head 原链表的头节点
     * @param index
     * @param val
     * @return 新链表的头节点
     */
    LinkNode* addAtIndex(LinkNode* head, int index, int val) {
        int cnt = 0;
        LinkNode* tmp = head;
        while (tmp != nullptr) {
            if(cnt == index) {
                LinkNode* cur = new LinkNode;
                cur->val = val;
                cur->next = tmp->next->next;
                tmp->next = cur;
            }
            tmp = tmp->next;
            cnt++;
        }
        return head;
    }

    /**
     * 如果索引 index 有效，则删除链表中的第 index 个节点。
     * @param head 原链表的头节点
     * @param index
     * @return 新链表的头节点
     */
    LinkNode* deleteAtIndex(LinkNode* head, int index) {
        if (head != nullptr && index == 0) {
            LinkNode* cur = head;
            head = head -> next;
            delete cur;
        }
        int cnt = 0;
        LinkNode* tmp = head;
        while (tmp != nullptr) {
            if(cnt == index-1) {
                LinkNode* cur = tmp->next;
                tmp->next = tmp->next->next;
                delete cur;
            }
            tmp = tmp->next;
            cnt++;
        }
        return head;
    }

    /**
     * 翻转链表
     * @param head 原链表的头节点
     * @return
     */
    LinkNode* reverse(LinkNode* head) {
        LinkNode* pre = nullptr;
        LinkNode* cur = head;
        while (cur != nullptr) {
//            LinkNode *tempPre = cur;
//            LinkNode *tempCur = cur->next;
//            cur->next = pre;
//            pre = tempPre;
//            cur = tempCur;


            LinkNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    /**
     * 两两交换链表中相邻的节点
     * @param head 原链表的头节点
     * @return
     */
    LinkNode* changeNode(LinkNode* head) {
        LinkNode *dummyHead = new LinkNode;
        dummyHead->val = -1;
        dummyHead->next = head;

        LinkNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            LinkNode *temp1 = cur->next;
            LinkNode *temp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }

    /**
     * 删除链表的倒数第 n 个结点，并且返回链表的头结点
     * @param head 原链表的头节点
     * @param n 倒数第 n 个结点
     * @return
     */
    LinkNode* removeNthFromEnd(LinkNode* head, int n) {
        LinkNode *dummyHead = new LinkNode;
        dummyHead->val = -1;
        dummyHead->next = head;
        LinkNode *fast = dummyHead;
        LinkNode *slow = dummyHead;
        n += 1;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        LinkNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummyHead->next;
    }

    /**
     * 判断链表是否有环 如果有环，如何找到这个环的入口
     * @param head
     * @return 环的入口指针
     */
    LinkNode *detectCycle(LinkNode *head) {
        LinkNode *fast = head;
        LinkNode *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                LinkNode* index1 = fast;
                LinkNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }

};

#endif //PROGRAMMERCARL_MYLINKNODE_H
