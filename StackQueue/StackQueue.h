//
// Created by YJ_1223 on 2024/1/30.
//

#ifndef PROGRAMMERCARL_STACKQUEUE_H
#define PROGRAMMERCARL_STACKQUEUE_H

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class MyStackQueue {
private:
    class MyMotonicQueue{
    public:
        deque<int> que;
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value==que.front())
                que.pop_front();
        }

        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back())
                que.pop_back();
            que.push_back(value);
        }

        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }

    };

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

    /**
     * 根据 逆波兰表示法，求表达式的值。
     * 有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式
     * @param tokens
     * @return
     */
    int evalRPN(vector<string>& tokens) {
        stack<long long> stack;
        long long res=0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = stack.top();
                stack.pop();
                long long num2 = stack.top();
                stack.pop();
                if (tokens[i] == "+"){
                    res = num1 + num2;
                }
                if (tokens[i] == "-"){
                    res = num2 - num1;
                }
                if (tokens[i] == "*"){
                    res = num1 * num2;
                }
                if (tokens[i] == "/"){
                    res = num2 / num1;
                }
                stack.push(res);
            } else {
                stack.push(stoll(tokens[i]));
            }
        }
        res = stack.top();
        return res;
    }

    /**
     * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。滑动窗口每次只向右移动一位。
     * @param nums
     * @param k
     * @return
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyMotonicQueue que;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
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
