#include <numeric>
#include <vector>
//
// Created by vinayak on 02-08-2024.
//
using namespace std;

int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int i=0,j=0;
    int total = accumulate(nums.begin(),nums.end(),0);
    int curr = 0;
    int maxC = 0;
    while (j < 2*n) {
        if (nums[j%n] == 1) {
            curr++;
        }
        if (j-i+1 > total) {
            curr -= nums[i%n];
            i++;
        }
        maxC = max(maxC,curr);
        j++;
    }
    return total-maxC;
}