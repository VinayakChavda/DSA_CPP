//
// Created by vinayak on 07-07-2024.
//
using namespace std;

int multiplier(int i,int n) {
    int ans = 1;
    for (int a=0;a<n;a++) {
        ans *= i;
    }
    return ans;
}

int nthRootOfM(int n,int m) {
    int low = 1;
    int high = m;
    while (high >= low) {
        int mid = (high+low)/2;
        if (multiplier(mid,n) == m) return mid;
        if (multiplier(mid,n) > m) {
            high = mid-1;
        }else {
            low = mid +1;
        }
    }
    return -1;
}