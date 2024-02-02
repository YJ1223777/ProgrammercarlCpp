//
// Created by YJ_1223 on 2024/1/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    static vector<int> squareArray(vector<int>& nums){
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> result(nums.size());
        while (k > 0){
            if (nums[i] * nums[i] < nums[j] * nums[j]){
                result[k--] = nums[j] * nums[j];
                j--;
            } else{
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> array = {-4,-1,0,1,3};
    for (int i = 0; i < array.size(); i++) {
        cout << Solution::squareArray(array)[i] << endl;
    }
    return 0;
}
