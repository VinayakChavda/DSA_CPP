#include <algorithm>
#include <future>
//
// Created by vinayak on 01-07-2024.
//
using namespace std;

// input   arr1[] = {1,3,5,7}   arr2[] = {0,2,6,8,9}
// output  arr1[] = {0,1,2,3}   arr2[] = {5,6,7,8,9}

void mergeSorted(long long arr1[],long long arr2[],int n,int m) {
    int left = n-1;
    int right = 0;
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }else {
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}