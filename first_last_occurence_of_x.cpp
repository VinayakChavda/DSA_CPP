#include <utility>
#include <vector>
//
// Created by vinayak on 04-07-2024.
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

int upperBound(vector<int> &arr,int x) {
    int n=arr.size();
    int low =0;
    int high = n-1;
    int ans = n;
    while (low <= high) {
        int mid = (low+high)/2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}

pair<int,int> firstLastOccurenceOfK(vector<int> &arr,int k) {
    int n = arr.size();
    int lb = lowerBound(arr,k);
    if (lb = n || arr[lb] != k) return {-1,-1};
    return {lb , upperBound(arr,k)-1};
}