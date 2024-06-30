#include <vector>
//
// Created by vinayak on 30-06-2024.
//
using namespace std;

vector<int> generateRow(int row) {
    int ans = 1;
    vector<int> res;
    res.push_back(1);
    for (int col=1;col<row;col++) {
        ans = ans * (row-col);
        ans = ans/col;
        res.push_back(ans);
    }
    return res;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i=1;i<=numRows;i++) {
        res.push_back(generateRow(i));
    }
    return res;
}