#include <map>
#include <queue>
#include <set>
#include <vector>
//
// Created by vinayak on 17-07-2024.
//
using namespace std;
#include "TreeNode.h"

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left != NULL) {
            todo.push({node->left,{x-1,y+1}});
        }
        if (node->right != NULL) {
            todo.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}