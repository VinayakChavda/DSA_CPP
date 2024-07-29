//
// Created by vinayak on 29-07-2024.
//
using namespace std;
#include "DisjoinSet.h"

int makeConnected(int n, vector<vector<int>>& connections) {
    DisjoinSet ds(n);
    int cntExtras = 0;
    for (auto it:connections) {
        int u = it[0];
        int v = it[1];
        if (ds.findUpr(u) == ds.findUpr(v)) {
            cntExtras++;
        }
        else {
            ds.unionByRank(u,v);
        }
    }
    int cntC = 0;
    for (int i=0;i<n;i++) {
        if (ds.findUpr(i) == i) {
            cntC++;
        }
    }
    int ans = cntC-1;
    if (cntExtras >= ans) return ans;
    return -1;
}