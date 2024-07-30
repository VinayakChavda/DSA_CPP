#include <set>
//
// Created by vinayak on 30-07-2024.
//
using namespace std;
#include "DisjoinSet.h"

bool isValid(int row,int col,int n) {
    return row >= 0 && row < n && col >=0 && col <n;
}

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjoinSet ds(n*n);
    for (int row=0;row<n;row++) {
        for (int col=0;col<n;col++) {
            if (grid[row][col] == 0) continue;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for (int i=0;i<4;i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (isValid(nrow,ncol,n) && grid[nrow][ncol] == 1) {
                    int node = row*n + col;
                    int adjNode = nrow*n + ncol;
                    ds.unionBySize(node,adjNode);
                }
            }
        }
    }

    int mx = 0;
    for (int row=0;row<n;row++) {
        for (int col=0;col<n;col++) {
            if (grid[row][col] == 1) continue;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            set<int> components;
            for (int i=0;i<4;i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (isValid(nrow,ncol,n)) {
                    if (grid[nrow][ncol] == 1) {
                        components.insert(ds.findUpr(nrow*n+ncol));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it:components) {
                sizeTotal += ds.size[it];
            }
            mx = max(mx,sizeTotal+1);
        }
    }
    for (int cellNo = 0; cellNo < n * n; cellNo++) {
        mx = max(mx, ds.size[ds.findUpr(cellNo)]);
    }
    return mx;

}