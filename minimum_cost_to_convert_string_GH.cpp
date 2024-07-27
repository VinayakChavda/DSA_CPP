#include <queue>
#include <string>
#include <unordered_map>
#include <valarray>
#include <vector>
//
// Created by vinayak on 27-07-2024.
//
using namespace std;

void dijkstra(char& ch,unordered_map<char,vector<pair<char,int>>> &adj,vector<vector<long long>>& matrix) {
    priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
    pq.push({0,ch});
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        char node = it.second;
        for (auto iter : adj[node]) {
            int edgW = iter.second;
            char adjNode = iter.first;
            if (matrix[ch-'a'][adjNode-'a'] > edgW + dis) {
                matrix[ch-'a'][adjNode-'a'] = edgW + dis;
                pq.push({edgW+dis,adjNode});
            }
        }
    }
    return;
}

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    unordered_map<char,vector<pair<char,int>>> adj;
    for (int i=0;i<original.size();i++) {
        adj[original[i]].push_back({changed[i],cost[i]});
    }
    vector<vector<long long>> matrix(26,vector<long long>(26,INT_MAX));
    for (int i=0;i<source.length();i++) {
        char ch = source[i];
        dijkstra(ch,adj,matrix);
    }
    long long ans = 0;
    for (int i=0;i<source.length();i++) {
        if (source[i] == target[i]) {
            continue;
        }
        if (matrix[source[i]-'a'][target[i]-'a'] == INT_MAX) {
            return -1;
        }
        ans += matrix[source[i]-'a'][target[i]-'a'];
    }
    return ans;
}
