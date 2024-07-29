#include <vector>
//
// Created by vinayak on 29-07-2024.
//
#include <algorithm>

#include "DisjoinSet.h"
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges;
    for (int i=0;i<V;i++) {
        for (auto it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = it[2];
            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjoinSet ds(V);
    sort(edges.begin(),edges.end());
    int msWt = 0;
    for (auto it :edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUpr(u) != ds.findUpr(v)) {
            msWt += wt;
            ds.unionByRank(u,v);
        }
    }
    return msWt;

}