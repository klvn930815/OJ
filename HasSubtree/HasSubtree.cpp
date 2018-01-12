//
// Created by Qiezz on 18-1-10.
//
#include <iostream>
#include <queue>
using namespace std;

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) {
            return false;
        }
        queue<TreeNode*> q;
        q.push(pRoot1);
        TreeNode *cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if (pRoot2->val == cur->val){
//                EqualTree(cur,pRoot2);
                if(EqualStruct(cur, pRoot2)){
                    return true;
                }
            }
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        return false;
    }
    bool EqualTree(TreeNode* p1, TreeNode* p2){
        if (!p1 && !p2) return true;
        if(p1 && p2 && (p1->val == p2->val)) {
            return EqualTree(p1->left, p2->left) && EqualTree(p1->right, p2->right);
        }
        return false;
    }
    bool EqualStruct(TreeNode* p1, TreeNode* p2){
        if(!p2) return true;
        if(p1 && p2 && (p1->val == p2->val)) {
            return EqualStruct(p1->left, p2->left) && EqualStruct(p1->right, p2->right);
        }
        return false;
    }
};
