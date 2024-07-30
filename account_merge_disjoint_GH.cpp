#include <algorithm>
#include <string>
#include <unordered_map>
//
// Created by vinayak on 30-07-2024.
//
using namespace std;

#include "DisjoinSet.h"

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjoinSet ds(n);
    unordered_map<string,int> mapMailNode;
    for (int i=0;i<n;i++) {
        for (int j=1;j<accounts[i].size();j++) {
            if (mapMailNode.find(accounts[i][j]) == mapMailNode.end()) {
                mapMailNode[accounts[i][j]] = i;
            }else {
                ds.unionByRank(i,mapMailNode[accounts[i][j]]);
            }
        }
    }

    vector<string> mergedMail[n];
    for (auto it : mapMailNode) {
        string mail = it.first;
        int node = ds.findUpr(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i=0;i<n;i++) {
        if (mergedMail[i].size() ==0) continue;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for (auto it : mergedMail[i]) {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}