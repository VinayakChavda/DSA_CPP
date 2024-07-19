#include <queue>
//
// Created by vinayak on 19-07-2024.
//
using namespace std;
#include "TreeNode.h"

int widthOfBinaryTree(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int ans = 0;
    queue<pair<TreeNode*,int>> todo;
    todo.push({root,0});
    while (!todo.empty()) {
        int size = todo.size();
        int mmin = todo.front().second;
        int first,second;
        for (int i=0;i<size;i++) {
            int curr = todo.front().second - mmin;
            TreeNode* curr_node = todo.front().first;
            todo.pop();
            if (i == 0) first = curr;
            if(i == size-1) second = curr;
            if (curr_node->left) {
                todo.push({curr_node->left,2*curr+1});
            }
            if (curr_node->right) {
                todo.push({curr_node->right,2*curr+2});
            }
        }
        ans = max(ans,second-first+1);
    }
    return ans;
}
