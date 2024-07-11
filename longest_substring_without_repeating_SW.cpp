#include <string>
#include <vector>
//
// Created by vinayak on 11-07-2024.
//
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n==0) return 0;
    vector<int> hash(256,-1);
    int l=0,r=0;
    int maxLen = 0;
    while (r < n) {
        if (hash[s[r]] != -1) {
            l = max(l,hash[s[r]]+1);
        }
        hash[s[r]] = r;
        int len = r-l+1;
        maxLen = max(maxLen,len);
        r++;
    }
    return maxLen;
}