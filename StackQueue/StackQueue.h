//
// Created by YJ_1223 on 2024/1/30.
//

#ifndef PROGRAMMERCARL_STACKQUEUE_H
#define PROGRAMMERCARL_STACKQUEUE_H

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class MyStackQueue {
public:

    MyStackQueue()= default;

    /**
     * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效
     * 有效字符串需满足:左括号必须用相同类型的右括号闭合;左括号必须以正确的顺序闭合;注意空字符串可被认为是有效字符串
     * @param s
     * @return
     */
    bool isValid(string s) {
        stack<char> stack;
        if (s.size() %2 != 0)
            return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stack.push(')');
            else if (s[i] == '[')
                stack.push(']');
            else if (s[i] == '{')
                stack.push('}');
            else if (stack.empty() || stack.top() != s[i])
                return false;
            else
                stack.pop();
        }
        return stack.empty();
    }

    /**
     * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们
     * 在 S 上反复执行重复项删除操作，直到无法继续删除
     * @param s
     * @return
     */
    string removeDuplicates(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (stack.empty() || stack.top() != s[i])
                stack.push(s[i]);
            else
                stack.pop();
        }
        string res = "";
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }



};


class MyQueue {
public:
    MyQueue()=default;

    /**
    * 使用栈实现队列的下列操作：
    * push(x) -- 将一个元素放入队列的尾部。
    * pop() -- 从队列首部移除元素。
    * peek() -- 返回队列首部的元素。
    * empty() -- 返回队列是否为空。
    */

    stack<int> stackIn;
    stack<int> stackOut;

    void push(int x) {
        stackIn.push(x);
    }

    int pop() {
        if (stackOut.empty()) {
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int res = stackOut.top();
        stackOut.pop();
        return res;
    }

    int peek() {
        int res = this->pop(); // 复用以上实现的pop函数
        stackOut.push(res);
        return res;
    }

    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }

};


class MyStack {
public:
    MyStack()=default;

    /**
    * 使用栈实现队列的下列操作：
    * push(x) -- 元素 x 入栈
    * pop() -- 移除栈顶元素
    * top() -- 获取栈顶元素
    * empty() -- 返回栈是否为空
    */

    queue<int> que;

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--) {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.pop();
        return res;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }

};

#endif //PROGRAMMERCARL_STACKQUEUE_H
