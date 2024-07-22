#include <queue>
#include <vector>
//
// Created by vinayak on 22-07-2024.
//
using namespace std;

void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid) {
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        vector<pair<int,int>> coord = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto it : coord) {
            int nrow = row + it.first;
            int ncol = col + it.second;
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                bfs(i,j,vis,grid);
                cnt++;
            }
        }
    }
    return cnt;
}