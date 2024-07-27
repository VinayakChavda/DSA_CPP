#include <queue>
#include <vector>
//
// Created by vinayak on 27-07-2024.
//
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 ||  grid[n-1][n-1]) return -1;
    queue<pair<int,pair<int,int>>> q;
    vector<vector<int>> dis(n,vector<int>(n,1e9));
    q.push({0,{0,0}});
    dis[0][0] = 0;
    while (!q.empty()) {
        int dist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        for (int i=-1;i<=1;i++) {
            for (int j=-1;j<=1;j++) {
                int nrow = row + i;
                int ncol = col + j;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && dist + 1 < dis[nrow][ncol]) {
                    dis[nrow][ncol] = 1+dist;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
    }
    return dis[n-1][n-1] == 1e9 ? -1 : dis[n-1][n-1]+1;
}