//
// Created by vinayak on 29-07-2024.
//

#include "DisjoinSet.h"

DisjoinSet::DisjoinSet(int n) {
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n + 1);
    for (int i=0;i<=n;i++) {
        parent[i] = i;
    }
}

int DisjoinSet::findUpr(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findUpr(parent[node]);
}

void DisjoinSet::unionByRank(int u, int v) {
    int ult_u = findUpr(u);
    int ult_v = findUpr(v);
    if (ult_u == ult_v) return;
    if (rank[ult_u] < rank[ult_v]) {
        parent[ult_u] = ult_v;
    }else if(rank[ult_u] > rank[ult_v]) {
        parent[ult_v] = ult_u;
    }else {
        parent[ult_v] = ult_u;
        rank[ult_u]++;
    }
}

void DisjoinSet::unionBySize(int u, int v) {
    int ult_u = findUpr(u);
    int ult_v = findUpr(v);
    if (ult_u == ult_v) return;
    if (size[ult_u] < size[ult_v]) {
        parent[ult_u] = ult_v;
        size[ult_v] += size[ult_u];
    }else {
        parent[ult_v] =ult_u;
        size[ult_u] += size[ult_v];
    }
}



