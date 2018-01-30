//
// Created by Qiezz on 18-1-29.
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int depth = 0;
        return IsBalanced(pRoot, depth);
    }
    bool IsBalanced(TreeNode* pRoot, int& depth){
        int left, right;
        if(!pRoot){
            depth = 0;
            return true;
        }
        if(IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right)){
            if(abs(left - right) <= 1){
                depth = left > right ? left + 1 : right + 1;
                return true;
            }
        }
        return false;
    }
};