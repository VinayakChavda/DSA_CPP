#include <limits.h>
#include <map>
#include <vector>
#include "stdlib.h"
//
// Created by vinayak on 20-07-2024.
//
using namespace std;
#include "TreeNode.h"

int findLeftH(TreeNode* root) {
    int h = 0;
    while (root) {
        h++;
        root = root->left;
    }
    return h;
}
int findRightH(TreeNode* root) {
    int h = 0;
    while (root) {
        h++;
        root = root->right;
    }
    return h;
}

int countTotalNodes(TreeNode* root) {
    if (root == NULL) return 0;
    int lh = findLeftH(root);
    int rh = findRightH(root);
    if (rh == lh) return (1<<lh)-1;
    return 1+countTotalNodes(root->left)+countTotalNodes(root->right);
}