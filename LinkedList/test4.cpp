//
// Created by YJ_1223 on 2024/1/19.
// 删除链表的倒数第 n 个结点，并且返回链表的头结点
//

#include "MyLinkNode.h"

int main() {
    Solution solution;
    LinkNode *listHead1 = solution.creatList(5);
    listHead1 = solution.removeNthFromEnd(listHead1,0);
    solution.showList(listHead1);
    return 0;
}
