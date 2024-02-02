//
// Created by YJ_1223 on 2024/1/14.
// 二分法查找
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    static int search(vector<int>& nums, int target){
        int length = nums.size();
        int left = 0;
        int right = length - 1;
        while (left <= right){
            int middle = left + (right - left)/2;
            if(nums[middle] < target){
                left = middle + 1;
            } else if(nums[middle] > target){
                right = middle - 1;
            } else if(nums[middle] == target){
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    cout << "Array0" << endl;
    vector<int> array = {-2,1,3,7,9,12,50};
    cout << Solution::search(array,-1) << endl;
    return 0;
}
