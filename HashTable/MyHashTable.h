//
// Created by YJ_1223 on 2024/1/21.
//

#ifndef PROGRAMMERCARL_MYHASHTABLE_H
#define PROGRAMMERCARL_MYHASHTABLE_H

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class MyHashTableSolution {
public:

    /**
     * 有效字母的异位
     * @param s1
     * @param s2
     * @return
     */
    bool isAnagram(string s1, string s2) {
        int record[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            record[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            record[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * 两个数组的交集
     * @param nums1
     * @param nums2
     * @return
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 查找值为key的元素，如果找到，则返回一个指向该元素的正向迭代器；
            // 如果没找到，则返回一个与end()方法相同的迭代器
            if (nums1_set.find(num) != nums1_set.end()) {
                result.insert(num);
            }
        }
        return vector<int> (result.begin(), result.end());
    }

    /**
     * 取数值各个位上的数的平方之和
     * @param n
     * @return
     */
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }

    /**
     * 判断是否为快乐数
     * @param n
     * @return
     */
    bool isHappy(int n) {
        unordered_set<int> result;
        int sum;
        while (1) {
            sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 题目中说了会 无限循环，那么也就是说求和的过程中，sum会重复出现
            if (result.find(sum) != result.end()) {
                // sum重复出现了 返回false
                return false;
            } else {
                result.insert(sum);
            }
            n = sum;
        }
    }

    /**
     * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标
     * @param nums
     * @param target
     * @return
     */
    vector<int> twoNumSum(vector<int> nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if(iter != map.end()) {
//                cout << "map value: " << map[2] << endl;
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i],i));
        }

        return {};
    }

    /**
     * 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
     * @param listA
     * @param listB
     * @param listC
     * @param listD
     * @return
     */
    int fourNumAdd(vector<int> listA, vector<int> listB,vector<int> listC,vector<int> listD) {
        unordered_map<int, int> map;
        for (int a:listA) {
            for (int b:listB) {
                map[a+b]++;
            }
        }
        int count = 0;
        for (int c:listC) {
            for (int d:listD) {
                if (map.find(0-(c+d)) != map.end())
                    count += map[0-(c+d)];
            }
        }
        return count;
    }

    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.size(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * 一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 找出所有满足条件且不重复的三元组
     * @param nums
     * @return
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 ){
                return result;
            }
            // 去重a
            if (i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0){
                    right--;
                } else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                } else {
                    // 去重b
                    while (right > left && nums[right] == nums[right-1])
                        right--;
                    // 去重c
                    while (right > left && nums[left] == nums[left+1])
                        left++;
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 找到结果后 双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }

    /**
     * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d
     * 使得 a + b + c + d = target  找出所有满足条件且不重复的四元组。
     * @param nums
     * @param target
     * @return
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i+1; j < nums.size()-1; j++) {
                // 去重a
                if (i>0 && nums[i] == nums[i-1]) {
                    continue;
                }
                // 去重b
                if (j>i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;

                while (right > left) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] > target){
                        right--;
                    } else if(nums[i] + nums[j] + nums[left] + nums[right] < target){
                        left++;
                    } else {
                        // 去重b
                        while (right > left && nums[right] == nums[right-1])
                            right--;
                        // 去重c
                        while (right > left && nums[left] == nums[left+1])
                            left++;
                        result.push_back(vector<int>{nums[i], nums[j] ,nums[left], nums[right]});
                        // 找到结果后 双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }

        }
        return result;
    }


};

#endif //PROGRAMMERCARL_MYHASHTABLE_H
