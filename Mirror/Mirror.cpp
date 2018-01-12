//
// Created by Qiezz on 18-1-11.
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot){
            TreeNode* buffer = pRoot->right;
            pRoot->right = pRoot->left;
            pRoot->left = buffer;

            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};