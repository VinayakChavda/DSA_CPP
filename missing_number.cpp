//
// Created by vinayak on 26-06-2024.
//

#include <vector>
using namespace std;

int missingNumber(vector<int> nums) {
    // int sum = 0;
    // for (int i=0;i<arr.size();i++) {
    //     sum += arr[i];
    // }
    // int totalSum = n*(n-1)/2;
    // return totalSum - sum;

    int n = nums.size();
    int xor1 = 0;
    for (int i=1;i<=n;i++) {
        xor1 ^= i;
    }
    int xor2 = 0;
    for (int i=0;i<n;i++) {
        xor2 ^= nums[i];
    }
    return xor1^xor2;
}
