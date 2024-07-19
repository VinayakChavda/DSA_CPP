#include <queue>
#include <unordered_map>
#include <vector>
//
// Created by vinayak on 19-07-2024.
//
using namespace std;
#include "TreeNode.h"

void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_treck,TreeNode* target) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr->left != NULL) {
            parent_treck[curr->left] = curr;
        }
        if (curr->right != NULL) {
            parent_treck[curr->right] = curr;
        }
    }
}

vector<int> distanceK(TreeNode* root,TreeNode* target,int k) {
    unordered_map<TreeNode*,TreeNode*> paarent_treck;
    markParents(root,paarent_treck,target);

    unordered_map<TreeNode*,bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!q.empty()) {
        int size = q.size();
        if (curr_level++ == k) break;
        for (int i=0;i<size;i++) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (paarent_treck[current] && !visited[paarent_treck[current]]) {
                q.push(paarent_treck[current]);
                visited[paarent_treck[current]] = true;
            }
        }
    }
    vector<int> result;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }
    return result;
}