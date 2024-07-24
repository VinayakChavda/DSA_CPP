#include <queue>
#include <vector>
//
// Created by vinayak on 24-07-2024.
//
using namespace std;

bool check(int start,vector<vector<int>>& graph,vector<int>& col) {
    col[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto it : graph[curr]) {
            if (col[it] == -1) {
                col[it] = !col[curr];
                q.push(it);
            }else if(col[it] == col[curr]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> col(n,-1);
    for (int i=0;i<n;i++) {
        if (col[i] == -1) {
            if (check(i,graph,col) == false) return false;
        }
    }
    return true;
}