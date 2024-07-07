#include <cmath>
#include <vector>
//
// Created by vinayak on 07-07-2024.
//
using namespace std;

int findMax(vector<int> &arr) {
    int ans = INT_MIN;
    for (int i=0;i<arr.size();i++) {
        ans = max(ans,arr[i]);
    }
    return ans;
}

bool possible(vector<int> &arr,int mid,int threshold) {
    int sum = 0;
    for (int i=0;i<arr.size();i++) {
        sum += ceil((double)arr[i]/(double)mid);
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = findMax(nums);
    int ans = -1;
    while (high >= low) {
        int mid = (high+low)/2;
        if (possible(nums,mid,threshold)) {
            ans = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}