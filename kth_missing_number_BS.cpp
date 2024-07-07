#include <vector>
//
// Created by vinayak on 07-07-2024.
//
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while (high >= low) {
        int mid = (high+low)/2;
        int missing = arr[mid] - mid - 1;
        if (missing < k) {
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return k+high+1;
}