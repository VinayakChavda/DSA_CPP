#include <algorithm>

#include "stdlib.h"
//
// Created by vinayak on 16-07-2024.
//
using namespace std;
#include "TreeNode.h"

int solve(TreeNode* root,int& maxi){
    if(root == NULL) return 0;
    int left = max(0,solve(root->left,maxi));
    int right = max(0,solve(root->right,maxi));
    maxi = max(maxi,root->val + left + right);
    return root->val + max(left,right);
}
int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    solve(root,maxi);
    return maxi;
}