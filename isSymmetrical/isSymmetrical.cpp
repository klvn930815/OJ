//
// Created by Qiezz on 18-2-4.
//
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot){
            return true;
        }
        return compare(pRoot->left, pRoot->right);
    }
    bool compare(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        if(left && right){
            if(left->val == right ->val){
                return compare(left->left, right->right) && compare(left->right, right->left);
            }
        }
        return false;
    }
};