#include <limits.h>
#include <map>
#include <vector>
#include "stdlib.h"
//
// Created by vinayak on 20-07-2024.
//
using namespace std;
#include "TreeNode.h"

int minChanges(vector<int>& nums, int k) {
    map<int, int> mp;
    int maxi = INT_MIN;
    int n = nums.size();
    for(int i=0;i<n/2;i++) {
        int ab = abs(nums[i]-nums[n-i-1]);
        mp[abs(nums[i]-nums[n-i-1])]++;
        maxi = max(maxi,mp[ab]);
    }
    int total = 0;
    for (auto it : mp) {
        total += it.second;
        if(it.first <= 0 ) {
            total++;
        }
    }
    return total - maxi;
}