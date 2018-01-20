//
// Created by Qiezz on 18-1-12.
//

#include <iostream>
#include <vector>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> q;
        vector<int> output;
        TreeNode * cur;
        if (root){
            q.push(root);
            while (!q.empty()){
                cur = q.front();
                q.pop();
                output.push_back(cur->val);
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
        return output;
    }
};