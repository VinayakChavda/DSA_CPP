#include <map>
#include <queue>
//
// Created by vinayak on 20-07-2024.
//
using namespace std;
#include "TreeNode.h"

int findMaxDistance(map<TreeNode*,TreeNode*>& mpp,TreeNode* target) {
    queue<TreeNode*> q;
    q.push(target);
    map<TreeNode*,int> visited;
    visited[target] = 1;
    int maxi =0;
    while (!q.empty()) {
        int size = q.size();
        int fl = 0;
        for (int i=0;i<size;i++) {
            auto node = q.front();
            if (node->left && !visited[node->left]) {
                fl = 1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !visited[node->right]) {
                fl = 1;
                visited[node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] && !visited[mpp[node]]) {
                fl =1;
                visited[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl) maxi++;
    }
    return maxi;
}

TreeNode* bfsToMapParents(TreeNode* root,map<TreeNode*,TreeNode*>& mpp,int start) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while (!q.empty()) {
        TreeNode* node = q.front();
        if (node->val == start) res = node;
        q.pop();
        if (node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int amountOfTime(TreeNode* root, int start) {
    map<TreeNode*,TreeNode*> mpp;
    TreeNode* target = bfsToMapParents(root,mpp,start);
    int maxi = findMaxDistance(mpp,target);
    return maxi;
}