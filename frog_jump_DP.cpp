#include <vector>
//
// Created by vinayak on 11-08-2024.
//
using namespace std;
int n;
vector<vector<int>> memo;
bool solve(int index,vector<int>& stones,int k) {
     if (index == n-1) {
          return true;
     }
     if (memo[index][k] != -1) {
          return memo[index][k];
     }
     for (int i=index+1;i<n;i++) {
          if (stones[i] - stones[index] >= k-1 && stones[i] - stones[index] <= k+1) {
               if(solve(i,stones,stones[i]-stones[index])) {
                    return memo[index][k] = true;
               }
          }
     }
     return memo[index][k] = false;
}

bool canCross(vector<int>& stones) {
     n = stones.size();
     memo.resize(n,vector<int>(n+1,-1));
     for (int i=1;i<n;i++) {
          if (stones[i] - stones[0] == 1) {
               if(solve(i,stones,1)) {
                    return true;
               }
          }
     }
     return false;
}