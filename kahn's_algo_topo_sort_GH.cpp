#include <queue>
#include <vector>
//
// Created by vinayak on 24-07-2024.
//
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    int indegree[V] = {0};
    for(int i=0;i<V;i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i=0;i<V;i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    return ans;
}
