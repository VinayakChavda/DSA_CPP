#include <queue>
#include <vector>
//
// Created by vinayak on 28-07-2024.
//
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    queue<pair<int,int>> q;
    q.push({start,0});
    vector<int> dis(100000,1e9);
    int mod = 100000;
    dis[start]=0;
    while (!q.empty()) {
        auto node = q.front();
        int value = node.first;
        int steps = node.second;
        for (auto iter : arr) {
            int nvalue = (value * iter) % mod;
            int nsteps = steps + 1;
            if (dis[nvalue] > nsteps) {
                dis[nvalue] = nsteps;
                if (nvalue == end) return nsteps;
                q.push({nvalue,nsteps});
            }
        }
    }
    return -1;
}