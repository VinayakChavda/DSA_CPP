#include <vector>
//
// Created by vinayak on 03-07-2024.
//
using namespace std;

int lowerBound(vector<int> &arr,int x) {
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int ans = n;
    while (high >= low) {
        int mid = (low+high)/2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}