#include <vector>
//
// Created by vinayak on 12-08-2024.
//
using namespace std;
int M;
int N;
int solve(int row,int col,int dx[],int dy[],vector<vector<int>>& dp) {
    if (row < 0 || row >= M || col < 0 || col >= N) return 0;
    if (row == M-1 && col == N-1) return 1;
    if (dp[row][col] != -1) return dp[row][col];
    int total = 0;
    for (int i=0;i<2;i++) {
        int nRow = row + dx[i];
        int ncol = col + dy[i];
        total += solve(nRow,ncol,dx,dy,dp);
    }
    return dp[row][col] = total;
}

int uniquePaths(int m, int n) {
    M = m;
    N = n;
    int dx[2] = {0,-1};
    int dy[2] = {-1,0};
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0    ][0] = 0;
    for (int i=m-1;i >= 0;i--) {
        for (int j=n-1;j >= 0;j--) {
            int total = 0;
            for (int i=0;i<2;i++) {
                total += dp[]
            }
        }
    }
}