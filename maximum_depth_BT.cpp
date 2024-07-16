#include <algorithm>

#include "TreeNode.h"
#include "stddef.h"
//
// Created by vinayak on 16-07-2024.
//
using namespace std;
int maxD(TreeNode* root) {
    if (root == NULL) return 0;
    int left = maxD(root->left);
    int right = maxD(root->right);
    return max(left,right) + 1;
}
int maxDepth(TreeNode* root) {
    return maxD(root);
}