#include <stack>
#include <unordered_map>
#include <vector>
//
// Created by vinayak on 24-07-2024.
//
using namespace std;

bool dfs(int node,unordered_map<int,vector<int>>& adj,int vis[],int pathVis[],stack<int>& st) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node]) {
        if(!vis[it]) {
            if (dfs(it,adj,vis,pathVis,st) == true) return true;
        }else if(pathVis[it]) {
            return true;
        }
    }
    st.push(node);
    pathVis[node] = 0;
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,vector<int>> adj;
    for (auto it:prerequisites) {
        int a = it[0];
        int b = it[1];
        adj[b].push_back(a);
    }
    int vis[numCourses] = {0};
    int pathVis[numCourses] = {0};
    stack<int> st;
    vector<int> ans;
    for (int i=0;i<numCourses;i++) {
        if(!vis[i]) {
            if (dfs(i,adj,vis,pathVis,st) == true) {
                return ans;
            }
        }
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}