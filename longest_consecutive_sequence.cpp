#include <unordered_set>
#include <vector>
#include <bits/std_function.h>
//
// Created by vinayak on 29-06-2024.
//
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i=0;i<n;i++) {
        st.insert(nums[i]);
    }

    for (auto it : st) {
        if (st.find(it -1) == st.end()) {
            int x = it;
            int cnt = 1;
            while (st.find(x+1) != st.end()) {
                x++;
                cnt++;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}