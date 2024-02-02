//
// Created by YJ_1223 on 2024/1/18.
// 两两交换链表中相邻的节点
//
#include "MyLinkNode.h"

int main() {
    Solution solution;
    LinkNode *listHead1 = solution.creatList(5);
    listHead1 = solution.changeNode(listHead1);
    solution.showList(listHead1);
    return 0;
}
