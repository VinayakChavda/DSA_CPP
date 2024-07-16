#include <vector>
//
// Created by vinayak on 16-07-2024.
//
using namespace std;
#include "TreeNode.h"
#include "stdlib.h"

bool isLeafNode(TreeNode* root) {
    if (root->left == NULL && root->right == NULL) return true;
    return false;
}

void addLeftBoundry(TreeNode* root,vector<int>& res) {
    TreeNode* curr = root->left;
    while (curr) {
        if (isLeafNode(curr)) res.push_back(curr->val);
        if (curr->left != NULL) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundry(TreeNode* root,vector<int>& res) {
    TreeNode* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (isLeafNode(curr)) temp.push_back(curr->val);
        if (curr->right != NULL) curr = curr->right;
        else curr = curr->left;
    }
    for (int i=temp.size()-1;i>=0;i--) {
        res.push_back(temp[i]);
    }
}

void addLeaves(TreeNode* root,vector<int>& res) {
    if (isLeafNode(root)) {
        res.push_back(root->val);
        return;
    }
    if (root->left) addLeaves(root->left,res);
    if (root->right) addLeaves(root->right,res);
}

vector<int> printBoundry(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    if (!isLeafNode(root)) res.push_back(root->val);
    addLeftBoundry(root,res);
    addLeaves(root,res);
    addRightBoundry(root,res);
    return res;
}