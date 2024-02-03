//
// Created by YJ_1223 on 2024/1/30.
//

#include "StackQueue.h"

int main() {

    MyQueue *myQueue = new MyQueue();
    MyStack myStack = MyStack();
    MyStackQueue *myStackQueue = new MyStackQueue();

    // 1.用栈实现队列
//    myQueue->push(1);
//    myQueue->push(2);
//    cout << myQueue->pop() << endl;


    // 2.用队列实现栈
//    myStack.push(1);
//    myStack.push(2);
//    cout << myStack.pop() << endl;


    // 3.有效的括号
//    cout << myStackQueue->isValid("{}{}") << endl;


    // 4.删除字符串中的所有相邻重复项
//    cout << myStackQueue->removeDuplicates("abbaca") << endl;


    // 5.逆波兰表达式求值
//    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
//    cout << myStackQueue->evalRPN(tokens) << endl;


    // 6.滑动窗口最大值
//    vector<int> nums = {1,3,-1,-3,5,3,6,7};
//    vector<int> res = myStackQueue->maxSlidingWindow(nums,3);
//    for (int i = 0; i < res.size(); ++i) {
//        cout << res[i] << " ";
//    }

    // 7.前 K 个高频元素

    return 0;
}
