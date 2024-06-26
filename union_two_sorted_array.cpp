#include <vector>
//
// Created by vinayak on 26-06-2024.
//
using namespace std;

vector<int> sortedArrUnion(vector<int> a,vector<int> b) {
    int n1= a.size();
    int n2= b.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while (i < n1 && j < n2) {
        if (b[j] >= a[i]) {
            if (ans.size() == 0 || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        }else {
            if (ans.size() == 0 || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < n2) {
        if (ans.size() == 0 || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    while (i < n1) {
        if (ans.size() == 0 || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }

    return ans;
}
