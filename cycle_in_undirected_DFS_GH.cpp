#include <vector>
//
// Created by vinayak on 23-07-2024.
//
using namespace std;

bool dfs(int node,int parent,vector<int>& vis,vector<int> adj[]) {
    vis[node] = 1;
    for (auto adjecentNode : adj[node]) {
        if (!vis[adjecentNode]) {
            if (dfs(adjecentNode,node,vis,adj)) return true;
        }else if(adjecentNode != parent) return true;
    }
    return false;
}

bool isCycle(int V,vector<int> add[]) {
    vector<int> vis(V,0);
    for (int i=0;i<V;i++) {
        if (!vis[i]) {
            if (dfs(1,-1,vis,add)) return true;
        }
    }
    return false;
}