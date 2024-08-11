#include <algorithm>
#include <vector>
//
// Created by vinayak on 11-08-2024.
//
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int n = g.size();
    int m = s.size();
    int i=0,j=0;
    while(i < n && j < m){
        if(g[i] <= s[i]){
            i++;
            j++;
        }else if(g[i] > s[j]){
            j++;
        }
    }
    return i;
}