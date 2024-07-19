#include <vector>
//
// Created by vinayak on 19-07-2024.
//
using namespace std;
#include "TreeNode.h"

bool isNode(TreeNode *root,vector<int>& arr,int x) {
    if (!root) return false;
    arr.push_back(root->val);
    if (root->val == x) return true;
    if (isNode(root->left,arr,x) || isNode(root->right,arr,x)) return true;
    arr.pop_back();
    return false;
}

vector<int> getPath(TreeNode* root,int x) {
    vector<int> arr;
    if (root == NULL) return arr;
    isNode(root,arr,x);
    return arr;
}
