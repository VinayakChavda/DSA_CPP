//
// Created by vinayak on 29-07-2024.
//
using namespace std;
#include  "DisjoinSet.h"

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DisjoinSet ds(n);
    for (int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (isConnected[i][j] == 1) {
                ds.unionByRank(i,j);
            }
        }
    }
    int cnt=0;
    for (int i=0;i<n;i++) {
        if (ds.findUpr(i) == i) {
            cnt++;
        }
    }
    return cnt;
}
