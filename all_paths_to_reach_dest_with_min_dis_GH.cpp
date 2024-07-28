#include <limits.h>
#include <queue>
#include <vector>
//
// Created by vinayak on 28-07-2024.
//
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int,int>> adj[n];
    for (auto it : roads) {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(n,INT_MAX) , ways(n,0);
    dis[0] = 0;
    ways[0] = 1;
    pq.push({0,0,});
    int mod = (int)(1e9+7);
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;
            if(edW + dist < dis[adjNode]) {
                dis[adjNode] = edW + dist;
                pq.push({edW+dist,adjNode});
                ways[adjNode] = ways[node];
            }else if(dis[adjNode] == dist+edW) {
                ways[adjNode] = (ways[adjNode] + ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}