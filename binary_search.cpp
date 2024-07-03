#include <vector>
//
// Created by vinayak on 03-07-2024.
//
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while (high >= low) {
        int mid = (high + low)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) {
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return -1;
}