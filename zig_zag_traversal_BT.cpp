#include <queue>
#include <vector>
//
// Created by vinayak on 16-07-2024.
//
using namespace std;
#include "TreeNode.h"

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    bool leftToRight = true;
    while (!nodeQueue.empty()) {
        int size = nodeQueue.size();
        vector<int> row(size);
        for (int i=0;i<size;i++) {
            TreeNode* curr = nodeQueue.front();
            nodeQueue.pop();
            int index = leftToRight ? i : (size-1-i);
            row[index] = curr->val;
            if (curr->left != NULL) {
                nodeQueue.push(curr->left);
            }
            if (curr->right != NULL) {
                nodeQueue.push(curr->right);
            }
        }
        leftToRight = !leftToRight;
        res.push_back(row);
    }
    return res;
}
