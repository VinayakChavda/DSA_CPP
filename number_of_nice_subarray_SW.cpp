#include <vector>
//
// Created by vinayak on 15-07-2024.
//
using namespace std;

int countSum(vector<int> nums,int goal) {
    int n = nums.size();
    if (goal < 0) return 0;
    int r=0,l=0,sum=0,cnt=0;
    while (r<n) {
        sum += nums[r] % 2;
        while (sum > goal) {
            sum -= nums[l] % 2;
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return countSum(nums,k) - countSum(nums,k-1);
}