#include <map>
#include <vector>
//
// Created by vinayak on 15-07-2024.
//
using namespace std;

int countSum(vector<int> nums,int k) {
    int n = nums.size();
    int r=0,l=0,cnt=0;
    map<int,int> mpp;
    while (r<n) {
        mpp[nums[r]]++;
        while (mpp.size() > k) {
            mpp[nums[l]]--;
            if (mpp[nums[l]]== 0) {
                mpp.erase(nums[l]);
            }
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return countSum(nums,k) - countSum(nums,k-1);
}