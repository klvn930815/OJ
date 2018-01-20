//
// Created by Qiezz on 18-1-14.
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode * pre = NULL;
        ConvertNode(pRootOfTree, pre);
        while (pRootOfTree->left){
            pRootOfTree = pRootOfTree->left;
        }
        return pRootOfTree;
    }
    void ConvertNode(TreeNode* cur, TreeNode*& pre){
        if(cur){
            ConvertNode(cur->left, pre);
            cur->left = pre;
            if(pre){
                pre->right = cur;
            }
            pre = cur;
            ConvertNode(cur->right, pre);
        }
    }
};