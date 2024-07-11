#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
//
// Created by vinayak on 10-07-2024.
//
int noOfPainters(vector<int> &nums,int walls) {
    int painet = 1;
    int wallsPainter = 0;
    for (int i=0;i<nums.size();i++) {
        if (wallsPainter+nums[i] <= walls) {
            wallsPainter += nums[i];
        }else {
            wallsPainter = nums[i];
            painet++;
        }
    }
    return painet;
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while (high >= low) {
        int mid = (low+high)/2;
        int noOfpainter = noOfPainters(nums,mid);
        if (noOfpainter > k) {
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return low;
}