#include <queue>
#include <vector>
//
// Created by vinayak on 27-07-2024.
//
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int>> adj[n];
    for (auto it : flights) {
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>> q;
    // {stops,{node,dist}}
    q.push({0,{src,0}});
    vector<int> dist(n,1e9);
    dist[src] = 0;
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int dis = it.second.second;
        if (stops > k) continue;
        for (auto iter : adj[node]) {
            int edgW = iter.second;
            int adjNode = iter.first;
            if (dis + edgW < dist[adjNode]) {
                dist[adjNode] = dis + edgW;
                q.push({stops+1,{adjNode,dis+edgW}});
            }
        }
    }
    if (dist[dst] == 1e9) return -1;
    return dist[dst];
}