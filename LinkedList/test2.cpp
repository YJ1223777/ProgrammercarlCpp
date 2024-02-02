//
// Created by YJ_1223 on 2024/1/18.
// 反转一个单链表
//
#include "MyLinkNode.h"

int main() {
    Solution solution;
    LinkNode *listHead1 = solution.creatList(6);
    listHead1 = solution.reverse(listHead1);
    solution.showList(listHead1);
    return 0;
}
