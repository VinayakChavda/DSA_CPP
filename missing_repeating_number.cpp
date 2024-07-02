#include <vector>
//
// Created by vinayak on 02-07-2024.
//
using namespace std;
#define ll long long

vector<int> findMissingRepeating(vector<int> arr) {
    // **************************************** HASHING ***************************************************
    // int n = arr.size();
    // int hasharr[n+1]  = {0};
    // for (int i=0;i<n;i++) {
    //     hasharr[arr[i]]++;
    // }
    // int missing = -1;
    // int repeating = -1;
    // for(int i =1;i<=n;i++) {
    //     if (hasharr[i] == 2) {
    //         repeating = i;
    //     }else if(hasharr[i] == 0) {
    //         missing = i;
    //     }
    //     if (repeating != -1 && missing != -1) {
    //         break;
    //     }
    // }
    // return {repeating,missing};

    // **************************************** MATH ***************************************************

    ll n = arr.size();
    ll SN = (n * (n+1)) / 2;
    ll SN2 = (n*(n+1)*(2*n+1))/6;
    ll S = 0, S2 = 0;
    for (int i=0;i<n;i++) {
        S += arr[i];
        S2 += (ll)arr[i]*(ll)arr[i];
    }
    ll val1 = S - SN;
    ll val2 = S2 -SN2;
    val2 = val2/val1;
    ll x = (val1 + val2)/2;
    ll y = x - val1;
    return {(int)x,(int)y};
}
