//
// Created by YJ_1223 on 2024/1/15.
// 移除元素
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
//    带&表示传入函数的是vector的引用（即物理位置），函数内部对vector改动，vector就会改变；
//    不带&表示传入的是vector的复制品（开辟了另一块位置），函数内部对其改动，不会影响原本的vector；
    static int removeElement(vector<int>& nums, int val){
        int fast;
        int slow = 0;
        for (fast=0;fast<nums.size();fast++)
        {
            if(nums[fast] != val){

//                nums[slow] = nums[fast];
//                slow++;

// 上面两行代码可以简化
                nums[slow++] = nums[fast];

            }
        }
        return slow;
    }
};

int main() {
    vector<int> array = {1,3,2,3,4,5,6,3};
    cout << Solution::removeElement(array,6) << endl;
    return 0;
}
