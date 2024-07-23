#include <queue>
#include <vector>
//
// Created by vinayak on 23-07-2024.
//
using namespace std;

void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int dx[],int dy[]) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i=0;i<4;i++) {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> vis(n,vector<int>(m,0));
    for (int j=0;j<m;j++) {
        if (!vis[0][j] && grid[0][j] == 1) {
            bfs(0,j,vis,grid,dx,dy);
        }
        if (!vis[n-1][j] && grid[n-1][j] == 1) {
            bfs(n-1,j,vis,grid,dx,dy);
        }
    }
    for (int i=0;i<n;i++) {
        if (!vis[i][0] && grid[i][0] == 1) {
            bfs(i,0,vis,grid,dx,dy);
        }
        if (!vis[i][m-1] && grid[i][m-1] == 1) {
            bfs(i,m-1,vis,grid,dx,dy);
        }
    }
    int ans= 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!vis[i][j] && grid[i][j] == 1) {
                ans++;
            }
        }
    }
    return ans;
}

