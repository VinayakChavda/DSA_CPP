#include <vector>
//
// Created by vinayak on 28-06-2024.
//
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
     int n =  nums.size();
     vector<int> ans(n,0);
     int i=0;
     int j=1;
     for (int a=0;a<n;a++) {
          if (nums[a] > 0) {
               ans[i] = nums[a];
               i += 2;
          }else {
               ans[j] = nums[a];
               j += 2;
          }
     }
     return ans;
}