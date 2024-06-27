#include <map>
#include <vector>
//
// Created by vinayak on 27-06-2024.
//
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // ********************************************* MAP ***************************************************
    // vector<int> ans;
    // map<int,int> save;
    // for (int i=0;i<nums.size();i++) {
    //     if (save.find(target-nums[i]) != save.end()) {
    //         ans.push_back(i);
    //         ans.push_back(save[target-nums[i]]);
    //         break;
    //     }
    //     save[nums[i]] = i;
    // }
    // return ans;

    // ********************************************* TWO POINTER ************************************************

    int left = 0;
    int right = nums.size() -1;
    while (right > left) {
        int sum = nums[right] + nums[left];
        if (sum == target) {
            return vector<int>{right,left};
        }
        if (sum > target) {
            right--;
        }else {
            left++;
        }
    }
}


