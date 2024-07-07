//
// Created by vinayak on 07-07-2024.
//
using namespace std;

int findSqrt(int n) {
    int high = n;
    int low = 0;
    int ans = 1;
    while(high >= low) {
        int mid= (high+low)/2;
        if ((mid*mid) <= n) {
            ans = mid;
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return ans;
}