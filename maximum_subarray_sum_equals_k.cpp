#include <map>
#include <vector>
//
// Created by vinayak on 30-06-2024.
//
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    map<int,int> mpp;
    int cnt = 0;
    int sum = 0;
    mpp[0] = 1;
    for (int i=0;i<nums.size();i++) {
        sum += nums[i];
        int remove = sum - k;
        cnt += mpp[remove];
        mpp[sum] += 1;
    }
    return cnt;
}