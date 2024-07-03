#include <limits.h>
#include <vector>
//
// Created by vinayak on 03-07-2024.
//
using namespace std;

int subArrayWithMaxPeoduct(vector<int> &arr) {
    int n = arr.size();
    int prefix = 1;
    int suffix = 1;
    int ans = INT_MIN;
    for (int i=0;i<n;i++) {
        if (prefix == 0) prefix =1;
        if (suffix == 0) suffix =1;
        prefix *= arr[i];
        suffix *= arr[n-i+1];
        ans = max(ans,max(prefix,suffix));
    }
    return ans;
}