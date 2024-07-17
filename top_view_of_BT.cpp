//
// Created by vinayak on 17-07-2024.
//
#include <map>
#include <queue>
#include <vector>
using namespace std;
#include "TreeNode.h"


vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    map<int,int> mpp;
    queue<pair<TreeNode*,int>> todo;
    todo.push({root,0});
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* curr = p.first;
        int line = p.second();
        if (mpp.find(line) == mpp.end()) mpp[line] == curr->val;
        if (curr->left != NULL) {
            todo.push({curr->left,line-1});
        }
        if (curr->right != NULL) {
            todo.push({curr->right,line+1});
        }
    }
    for (auto it:mpp) {
        ans.push_back(it.second);
    }
    return ans;
}