#include <queue>
#include <vector>
using namespace std;
//
// Created by vinayak on 25-07-2024.
//



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }
        vector<int> indegree(V,0);
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
        return (ans.size() == numCourses);
    }

