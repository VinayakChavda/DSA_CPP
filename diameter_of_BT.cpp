#include <algorithm>
#include <wchar.h>
//
// Created by vinayak on 16-07-2024.
//
using namespace std;
#include "TreeNode.h"
int findDiameter(TreeNode* root,int& maxi) {
    if (root == NULL) return 0;
    int lh = findDiameter(root->left,maxi);
    int rh = findDiameter(root->right,maxi);
    maxi = max(maxi,lh+rh);
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxi = 0;
    findDiameter(root,maxi);
    return maxi;
}