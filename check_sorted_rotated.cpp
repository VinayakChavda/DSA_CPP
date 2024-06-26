//
// Created by vinayak on 25-06-2024.
//
using namespace std;
#include <vector>

bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i=0;i<n;i++) {
                if (nums[i] > nums[(i+1)%n]) {
                        count++;
                }
        }
        return count<=1;
}
