#include "stdlib.h"
//
// Created by vinayak on 16-07-2024.
//
using namespace std;

#include "TreeNode.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL) return (p == q);
    return (p->val == q->val) && isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
}