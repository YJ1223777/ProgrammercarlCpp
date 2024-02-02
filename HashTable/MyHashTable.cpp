//
// Created by YJ_1223 on 2024/1/21.
//

#include "MyHashTable.h"

int main() {
    MyHashTableSolution solution;

    // 1.有效的字母异位词
//    cout << solution.isAnagram("abbc","bbac") << endl;


    // 2.两个数组的交集
//    vector<int> nums1 = {9,8,6,6,1};
//    vector<int> nums2 = {6,6,1};
//    vector<int> res = solution.intersection(nums1,nums2);
//    vector<int>::iterator it = res.begin();
//    while (it != res.end()) {
//        cout << *it << " ";
//        it++;
//    }


    // 3.快乐数
//    int n = 19;
//    cout << solution.isHappy(18) << endl;


    // 4.两数之和
//    vector<int> nums = {2,7,3,6};
//    int target = 10;
//    vector<int>::iterator it = solution.twoNumSum(nums, target).begin();
//    while (it != solution.twoNumSum(nums, target).end()) {
//        cout << *it << " ";
//        it++;
//    }


    // 5.四数相加II
//    vector<int> listA = {1,2};
//    vector<int> listB = {-2,-1};
//    vector<int> listC = {-1,2};
//    vector<int> listD = {0,2};
//    cout << solution.fourNumAdd(listA, listB, listC, listD) << endl;


    // 6.救赎信
//    cout << solution.canConstruct("egp","abcdefg") << endl;


    // 7.三数之和
//    vector<int> nums = {-1, 0, 1, 2, -1, -4};
//    vector<vector<int>> result = solution.threeSum(nums);


    // 8.四数之和
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = solution.fourSum(nums,0);


    return 0;
}
