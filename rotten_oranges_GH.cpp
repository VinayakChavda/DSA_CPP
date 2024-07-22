#include <queue>
#include <vector>
//
// Created by vinayak on 22-07-2024.
//
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int n = grid.size();
    int m = grid[0].size();
    int days = 0,total = 0,cnt = 0;
    queue<pair<int,int>> rotten;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j] != 0) total++;
            if (grid[i][j] == 2) rotten.push({i,j});
        }
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    while (!rotten.empty()) {
        int k = rotten.size();
        cnt += k;
        while (k--) {
            int row = rotten.front().first;
            int col = rotten.front().second;
            rotten.pop();
            for (int i=0;i<4;i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow < 0 || nrow >= n || ncol <0 || ncol >= m || grid[nrow][ncol] != 1) continue;
                grid[nrow][ncol] = 2;
                rotten.push({nrow,ncol});
            }
        }
        if (!rotten.empty()) days++;
    }
    return total == cnt ? days : -1;
}