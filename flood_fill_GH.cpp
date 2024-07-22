#include <vector>
//
// Created by vinayak on 22-07-2024.
//
using namespace std;

void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int deltaX[],int deltaY[],int newColor,int initColor) {
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i=0;i<4;i++) {
        int nrow = row + deltaX[i];
        int ncol = col + deltaY[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor) {
            dfs(nrow,ncol,ans,image,deltaX,deltaY,newColor,initColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int deltaX[] = {-1,0,+1,0};
    int deltaY[] = {0,+1,0,-1};
    dfs(sr,sc,ans,image,deltaX,deltaY,color,initColor);
    return ans;
}