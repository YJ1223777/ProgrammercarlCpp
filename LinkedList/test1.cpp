//
// Created by YJ_1223 on 2024/1/18.
// 在链表类中实现这些功能：
// 1. get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// 2. addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// 3. addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// 4. addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为val的节点。
//    如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
// 5. deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
//
#include "MyLinkNode.h"

int main() {
    Solution solution;
    LinkNode *listHead1 = solution.creatList(10);

//    cout << solution.getIndex(listHead1,9) << endl;

//    listHead1 = solution.addAtHead(listHead1,100);
//    solution.showList(listHead1);

//    listHead1 = solution.addAtTail(listHead1,100);
//    solution.showList(listHead1);

//    listHead1 = solution.addAtIndex(listHead1,1,100);
//    solution.showList(listHead1);

    listHead1 = solution.deleteAtIndex(listHead1,5);
    solution.showList(listHead1);

    return 0;
}
