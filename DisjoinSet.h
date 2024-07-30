//
// Created by vinayak on 29-07-2024.
//

#ifndef DISJOINSET_H
#define DISJOINSET_H
#include <vector>

using namespace std;
class DisjoinSet {
public:
    vector<int> rank,parent,size;
    DisjoinSet(int n);
    int findUpr(int node);
    void unionByRank(int u,int v);
    void unionBySize(int u,int v);
};



#endif //DISJOINSET_H
