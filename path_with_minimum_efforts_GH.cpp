#include <queue>
#include <valarray>
#include <vector>
#include <bits/chrono.h>
//
// Created by vinayak on 27-07-2024.
//
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0] = 0;
    pq.push({0,{0,0}});
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if (row == n-1 && col == m-1) {
            return dis;
        }
        for (int i=0;i<4;i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]),dis);
                if (newEffort < dist[nrow][ncol]) {
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}