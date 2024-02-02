//
// Created by YJ_1223 on 2024/1/25.
//

#ifndef PROGRAMMERCARL_MYSTRING_H
#define PROGRAMMERCARL_MYSTRING_H

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class myString {
public:

    myString(){
        cout << "  " << endl;
    }

    /**
     * 将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
     * @param s
     */
    void reverseString(vector<char>& s) {
        for (int i = 0, j=s.size()-1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
    }

    /**
     * 给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
     * @param s
     * @param k
     * @return
     */
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i+=2*k) {
            if (i+k <= s.size()){
                reverse(s.begin()+i, s.begin()+i+k);
            } else {
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }

    /**
     * 将字符串中的字母字符保持不变，而将每个数字字符替换为number
     * @param s
     * @return
     */
    string replaceNumber(string s){
        int count = 0; // 统计数字的个数
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            }
        }
        // 扩充字符串s的大小，也就是每个空格替换成"number"之后的大小
        s.resize(s.size() + count * 5);
        int sNewSize = s.size();
        for (int i = sNewSize-1, j=sOldSize-1; j<i ; i--,j--) {
            if (s[j]<'0' || s[j]>'9'){
                s[i] = s[j];
            }
            else {
                s[i] = 'r';
                s[i - 1] = 'e';
                s[i - 2] = 'b';
                s[i - 3] = 'm';
                s[i - 4] = 'u';
                s[i - 5] = 'n';
                i -= 5;
            }
        }
        return s;
    }

    /**
     * 给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。
     * @param str
     * @param k
     * @return
     */
    string rightReverse(string str, int k) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + k);
        reverse(str.begin() + k, str.end());
        return str;
    }



    /**
     * KMP算法
     * 计算 next 数组
     * @param next
     * @param string
     * @return
     */
    int* getNext(int* next, const string& string) {
        int j=0;
        next[0] = 0;
        for(int i=1;i<string.size();i++) {
            while (j>0 && string[i]!=string[j]) {
                j = next[j-1];
            }
            if(string[i]==string[j]){
                j++;
            }
            next[i] = j;
        }
        return next;
    }

    /**
     * KMP算法
     * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)
     * 如果不存在，则返回  -1。
     * @param haystack
     * @param needle
     * @return
     */
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j=0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j>0 && haystack[i]!=needle[j]) {
                j = next[j-1];
            }
            if (haystack[i]==needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }

    /**
     * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成
     * @param s
     * @return
     */
    bool repeatedSubstringPattern(string s) {
        string t = s+s;
        t.erase(t.begin());
        t.erase(t.end()-1); // end()函数返回一个迭代器，指向字符串的末尾(最后一个字符的下一个位置)
        if (t.find(s)!=string::npos) {
            return true;
        }
        return false;
    }

};

#endif //PROGRAMMERCARL_MYSTRING_H
