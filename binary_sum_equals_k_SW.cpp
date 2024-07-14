//
// Created by vinayak on 14-07-2024.
//

#include <vector>
using namespace std;

int countSum(vector<int> nums,int goal) {
    int n = nums.size();
    if (goal < 0) return 0;
    int r=0,l=0,sum=0,cnt=0;
    while (r<n) {
        sum += nums[r];
        while (sum > goal) {
            sum -= nums[l];
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return countSum(nums,goal) - countSum(nums,goal-1);
}
