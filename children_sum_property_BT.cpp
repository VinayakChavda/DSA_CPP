//
// Created by vinayak on 19-07-2024.
//
using namespace std;
#include "TreeNode.h"

void changeTree(TreeNode* root) {
    if (!root) return;
    int child = 0;
    if (root->left) {
        child += root->left->val;
    }
    if (root->right) {
        child += root->right->val;
    }
    if (child >= root->val) root->val = child;
    else {
        if (root->left) root->left->val = child;
        else if (root->right) root->right->val = child;
    }
    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left) tot += root->left->val;
    if (root->right) tot += root->right->val;
    root->val = tot;
}