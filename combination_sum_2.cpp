#include <algorithm>
#include <vector>
//
// Created by vinayak on 13-08-2024.
//
using namespace std;

void solve(int index,vector<int>& candidates,int target,vector<int>& temp,vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    for (int i=index;i<candidates.size();i++) {
        if (i > index && candidates[i] == candidates[i-1]) continue;
        if (candidates[i] > target) break;
        temp.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],temp,ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    solve(0, candidates, target, temp, ans);
    return ans;
}