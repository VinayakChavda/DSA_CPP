#include <string.h>
//
// Created by vinayak on 30-07-2024.
//
using namespace std;
#include "DisjoinSet.h"

bool isValid(int row,int col,int n,int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjoinSet ds(n*m);
    int vis[n][m];
    memset(vis,0,sizeof vis);
    int cnt = 0;
    vector<int> ans;
    for (auto it : operators) {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for (int i=0;i<4;i++) {
            int adjR = row + dr[i];
            int adjC = col + dc[i];
            if (isValid(adjR,adjC,n,m)) {
                if (vis[adjR][adjC] == 1) {
                    int nodeNo = row * m + col;
                    int adjectNodeNo = adjR * m + adjC;
                    if (ds.findUpr(nodeNo) != ds.findUpr(adjectNodeNo)) {
                        cnt--;
                        ds.unionByRank(nodeNo,adjectNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}