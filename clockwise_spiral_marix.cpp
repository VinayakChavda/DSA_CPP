#include <vector>
//
// Created by vinayak on 08-08-2024.
//
using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> res;
    int steps = 0;
    int dir = 0;
    res.push_back({rStart,cStart});
    while (res.size() < (rows*cols)) {
        if (dir == 0 || dir == 2) steps++;
        for (int count = 0;count < steps;count++) {
            rStart += direction[dir][0];
            cStart += direction[dir][1];
            if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                res.push_back({rStart,cStart});
            }
        }
        dir = (dir+1)%4;
    }
    return res;
}