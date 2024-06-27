//
// Created by vinayak on 27-06-2024.
//

#include <map>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

    //******************************************* MAP *********************************************************
    // map<int,int> save;
    // int n = nums.size();
    // int maxi = 0;
    // int sum = 0;
    // for (int i=0;i<n;i++) {
    //     sum += nums[i];
    //     if (sum == k) {
    //         maxi = max(maxi,i+1);
    //     }
    //     int rem = sum - k;
    //     if (save.find(rem) != save.end()) {
    //         maxi = max(maxi,i - save[rem]);
    //     }
    //     if (save.find(sum) == save.end()) {
    //         save[sum] = i;
    //     }
    // }
    // return maxi;


    //******************************************* TWO POINTER **************************************************

    int maxi = 0;
    int left = 0;
    int right = 0;
    int n = nums.size();
    int sum = 0;
    while (right < n) {
        while (left <= right && sum >k) {
            sum -= nums[left];
            left++;
        }
        if (sum == k) {
            maxi = max(maxi,right - left +1);
        }
        right++;
        if(right < n) {
            sum += nums[right];
        }
    }
    return maxi;
}
