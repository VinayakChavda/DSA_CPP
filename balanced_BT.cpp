//
// Created by vinayak on 16-07-2024.
//
#include <algorithm>

#include "TreeNode.h"
#include "stddef.h"
using namespace std;
int maxD(TreeNode* root) {
    if (root == NULL) return 0;
    int left = maxD(root->left);
    int right = maxD(root->right);
    if(left == -1 || right == -1) return -1;
    if (abs(left-right) > 1) return -1;
    return max(left,right) + 1;
}
bool isBalanced(TreeNode* root) {
    return maxD(root) == -1 ? false : true;
}