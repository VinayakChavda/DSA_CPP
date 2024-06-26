//
// Created by vinayak on 25-06-2024.
//
using namespace std;
#include<vector>

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i=0;
    for (int j=1;j<n;j++) {
        if (nums[j] != nums[i]) {
            nums[i++]=nums[j];
        }
    }
    return i+1;
}