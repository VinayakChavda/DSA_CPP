#include <vector>
//
// Created by vinayak on 11-08-2024.
//
using namespace std;

int m,n;
void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis) {
    if (i < 0 || i>=m || j< 0 || j >=n || grid[i][j] == 0 || vis[i][j]) return;
    vis[i][j] = 1;
    dfs(i+1,j,grid,vis);
    dfs(i-1,j,grid,vis);
    dfs(i,j+1,grid,vis);
    dfs(i,j-1,grid,vis);
}

int noOfIsland(vector<vector<int>>& grid) {
    int isLand = 0;
    vector<vector<int>> vis(m,vector<int>(n,0));
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                dfs(i,j,grid,vis);
                isLand++;
            }
        }
    }
    return isLand;
}

int minDays(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int initial = noOfIsland(grid);
    if (initial == 0 || initial > 1) return 0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                int island = noOfIsland(grid);
                grid[i][j] = 1;
                if (island > 1 || island == 0) return 1;
            }
        }
    }
    return 2;
}