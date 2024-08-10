//
// Created by vinayak on 10-08-2024.
//

#include <string>
#include <vector>
using namespace std;

void dfs(pair<int,int> index,vector<int>& vis,vector<vector<int>>& matrix,int dx[],int dy[]) {
    int n = matrix.size();
    int row = index.first;
    int col = index.second;
    vis[n*row+col] = 1;
    for (int i=0;i<4;i++) {
        int nRow = row + dx[i];
        int nCol = col + dy[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && !vis[n*nRow + nCol] && matrix[nRow][nCol] == 0) {
            dfs({nRow,nCol},vis,matrix,dx,dy);
        }
    }
}

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    vector<vector<int>> matrix(n*3,vector<int>(n*3,0));
    vector<vector<vector<int>>> maptomat = {{{0,0,0},{0,0,0},{0,0,0}}, {{0,0,1},{0,1,0},{1,0,0}},{{1,0,0},{0,1,0},{0,0,1}}};
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            int index = grid[i][j] == ' ' ? 0 : (grid[i][j] == '/' ? 1 : 2);
            for (int k=0;k<3;k++) {
                for (int l=0;l<3;l++) {
                    matrix[i*3 + k][j*3+l] = maptomat[index][k][l];
                }
            }
        }
    }
    int count = 0;
    int s = matrix.size();
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<int> vis(s*s,0);
    for (int i=0;i<s;i++) {
        for (int j=0;j<s;j++) {
            if (matrix[i][j] == 0 && !vis[i*s+j]){
                dfs({i,j},vis,matrix,dx,dy);
                count++;
            }
        }
    }
    return count;
}
