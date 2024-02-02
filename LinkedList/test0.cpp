//
// Created by YJ_1223 on 2024/1/14.
// 移除链表元素
//
#include "MyLinkNode.h"

using namespace std;

int main() {
    Solution solution;
    LinkNode *listHead1 = solution.creatList(10);
    listHead1 = solution.removeElementWithDumHead(listHead1,6);
    solution.showList(listHead1);
    return 0;
}
