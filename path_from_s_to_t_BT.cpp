#include <string>
//
// Created by vinayak on 16-07-2024.
//
using namespace std;
#include "TreeNode.h";

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;
    if (root->val == p || root->val == q) return root;
    TreeNode* leftN = lowestCommonAncestor(root->left,p,q);
    TreeNode* rightN = lowestCommonAncestor(root->right,p,q);

    if (leftN != NULL && rightN != NULL) return root;
    if (leftN != NULL) return leftN;
    return rightN;
}

bool findPath(TreeNode* LCA,int target,string& res) {
    if (LCA == NULL) return false;
    if (LCA->val == target) return true;

    res.push_back('L');
    if (findPath(LCA->left,target,res) == true) {
        return true;
    }
    res.pop_back();
    res.push_back('R');
    if (findPath(LCA->right,target,res) == true) {
        return true;
    }
    res.pop_back();
    return false;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    TreeNode* LCA = lowestCommonAncestor(root,startValue,destValue);

    string lcaToSrc = "";
    string lcaToDest = "";

    findPath(LCA,startValue,lcaToSrc);
    findPath(LCA,destValue,lcaToDest);

    string result = "";
    for (int i=0;i<lcaToSrc.length();i++) {
        result.push_back('U');
    }
    result += lcaToDest;
    return result;
}