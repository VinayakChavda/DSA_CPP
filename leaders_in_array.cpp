#include <limits.h>
#include <vector>
//
// Created by vinayak on 29-06-2024.
//
using namespace std;

// Leader :-  Everything on right side should be smaller

vector<int> superiorElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n-1;i>=0;i--) {
        if (arr[i] > maxi) {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }
    return ans;
}