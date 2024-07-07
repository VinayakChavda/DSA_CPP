#include <vector>

#include <climits>
#include <cmath>
//
// Created by vinayak on 07-07-2024.
//
using namespace std;
#define ll long long

int findMax(vector<int> &arr) {
    int ans = INT_MIN;
    for (int i=0;i<arr.size();i++) {
        ans = max(ans,arr[i]);
    }
    return ans;
}

int calTotalHour(vector<int> &arr,int hourly) {
    ll totalH = 0;
    int n = arr.size();
    for (int i=0;i<n;i++) {
        totalH += ceil((double)arr[i]/(double)hourly);
    }
    return (int)totalH;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = findMax(piles);
    while (low <= high) {
        int mid = (low+high)/2;
        int totalH = calTotalHour(piles,mid);
        if (totalH <= h) {
            high = mid-1;
        }else {
            low =mid+1;
        }
    }
    return low;
}