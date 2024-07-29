//
// Created by vinayak on 29-07-2024.
//

#ifndef DISJOINSET_H
#define DISJOINSET_H
#include <vector>

using namespace std;
class DisjoinSet {
    vector<int> rank,parent;
public:
    DisjoinSet(int n);
    int findUpr(int node);
    void unionByRank(int u,int v);
};



#endif //DISJOINSET_H
