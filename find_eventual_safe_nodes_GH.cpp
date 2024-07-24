#include <unordered_map>
#include <vector>
//
// Created by vinayak on 24-07-2024.
//
using namespace std;

bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis,vector<int>& check) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    for (auto it : adj[node]) {
        if(!vis[it]) {
            if (dfs(it,adj,vis,pathVis,check) == true) return true;
        }else if(pathVis[it]) {
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);
    vector<int> check(n,0);
    vector<int> ans;
    for (int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i,graph,vis,pathVis,check);
        }
    }
    for (int i=0;i<n;i++) {
        if (check[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}