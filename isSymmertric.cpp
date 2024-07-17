#include "stdlib.h"
//
// Created by vinayak on 17-07-2024.
//
using namespace std;
#include "TreeNode.h"

bool solveSymmetric(TreeNode* left,TreeNode* right) {
    if (left == NULL || right == NULL) {
        return left == right;
    }
    if (left->val != right->val) return false;
    return solveSymmetric(left->left,right->right) && solveSymmetric(left->right,right->left);
}

bool isSymmetric(TreeNode* root) {
    return solveSymmetric(root->left,root->right);
}