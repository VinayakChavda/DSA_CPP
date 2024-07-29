#include <queue>
#include <vector>
//
// Created by vinayak on 29-07-2024.
//
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    int ans = 0;
    vector<int> vis(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // {wt,node} no need to track the parent as here only sum is needed
    pq.push({0,0});
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int node = it.second;
        if (vis[node] == 1) continue;
        vis[node] = 1;
        ans += dis;
        for (auto iter : adj[node]) {
            int adjNode = iter[0];
            int edW = iter[1];
            if (!vis[adjNode]) pq.push({edW,adjNode});
        }
    }
    return ans;
}
