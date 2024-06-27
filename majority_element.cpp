#include <vector>
//
// Created by vinayak on 27-06-2024.
//
using namespace std;

// ****************************** MOORE'S VOTING ALGORITHAM *************************************************
int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int ele;
    for (int i=0;i<nums.size();i++) {
        if (cnt == 0) {
            cnt = 1;
            ele = nums[i];
        }
        else if(nums[i] == ele) {
            cnt++;
        }else {
            cnt--;
        }
    }
    return ele;
}