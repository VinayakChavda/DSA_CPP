#include <algorithm>
#include <vector>
using namespace std;
//
// Created by vinayak on 26-06-2024.
//
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}