#include <queue>
#include <vector>
//
// Created by vinayak on 23-07-2024.
//
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (mat[i][j] == 0) {
                vis[i][j] = 1;
                q.push({{i,j},0});
            }else {
                vis[i][j] = 0;
            }
        }
    }
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();
        dis[row][col] = step;
        for (int i=0;i<4;i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},step+1});
            }
        }
    }
    return dis;
}
