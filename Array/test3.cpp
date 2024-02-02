//
// Created by YJ_1223 on 2024/1/15.
// 长度最小的子数组
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    static int minSubArrayLen(vector<int>& nums, int s){
        int result = INT_MAX;
        int i = 0;
        int length = 0;
        int sum = 0;
        for(int j=0;j<nums.size();j++){
            sum += nums[j];
            // 滑动窗口
            while (sum >= s){
                length = j-i+1;
                result = result < length ? result : length;
                sum -= nums[i++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main() {
    vector<int> array = {2,3,1,2,4,3};
    cout << Solution::minSubArrayLen(array, 8) << endl;
    return 0;
}
