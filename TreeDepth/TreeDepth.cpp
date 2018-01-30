//
// Created by Qiezz on 18-1-29.
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
    int TreeDepth_alter(TreeNode* pRoot)
    {
        if(pRoot == NULL){
            return 0;
        }
        int left = TreeDepth_alter(pRoot->left);
        int right = TreeDepth_alter(pRoot->right);
        return left > right? left + 1: right + 1;
    }
    int TreeDepth(TreeNode* pRoot){
        TreeNode *cur, *last = pRoot;
        int level = 0;
        queue<TreeNode*> queue1;
        if(pRoot){
            level ++;
            queue1.push(pRoot);
            while(!queue1.empty()){
                cur = queue1.front();
                queue1.pop();
                if(cur->left){
                    queue1.push(cur->left);
                }
                if(cur->right){
                    queue1.push(cur->right);
                }
                if(cur == last){
                    if(!queue1.empty()){
                        level ++;
                        last = queue1.back();
                    }
                }
            }
        }
        return level;
    }
};