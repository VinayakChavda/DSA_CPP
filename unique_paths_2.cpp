#include <vector>
//
// Created by vinayak on 13-08-2024.
//
using namespace std;
int n;
int m;
int solve(int i,int j,vector<vector<int>>& grid,int dx[],int dy[],vector<vector<int>>& dp) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1) return 0;
    if (i == n-1 && j == m-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int total = 0;
    for (int x=0;x<2;x++) {
        int nRow = i + dx[x];
        int ncol = j + dy[x];
        total += solve(nRow,ncol,grid,dx,dy,dp);
    }
    return dp[i][j] = total;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    n = obstacleGrid.size();
    m = obstacleGrid[0].size();
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(0,0,obstacleGrid,dx,dy,dp);
}