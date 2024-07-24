#include <stack>
#include <vector>
//
// Created by vinayak on 24-07-2024.
//
using namespace std;

void dfs(int node,int vis[],vector<int> adj[],stack<int>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it,vis,adj,st);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    int vis[V] = {0};
    stack<int> st;
    for (int i=0;i<V;i++) {
        if (!vis[i]) dfs(i,vis,adj,st);
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}