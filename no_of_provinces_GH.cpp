#include <vector>
//
// Created by vinayak on 22-07-2024.
//
using namespace std;

void dfs(int node,vector<int> adjLs[],vector<int>& vis) {
    vis[node] = 1;
    for (auto it : adjLs[node]) {
        if (!vis[it]) {
            dfs(it,adjLs,vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int v  = isConnected.size();
    vector<int> adjLs[v];
    for (int i=0;i<v;i++) {
        for (int j=0;j<v;j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    vector<int> vis(v,0);
    int cnt = 0;
    for (int i=0;i<v;i++) {
        if (!vis[i]) {
            dfs(i,adjLs,vis);
            cnt++;
        }
    }
    return cnt;
}