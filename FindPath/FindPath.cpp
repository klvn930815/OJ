//
// Created by Qiezz on 18-1-13.
//

#include <iostream>
#include <vector>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> >output;
        if(root){
            int value = root->val;
            if(!root->left && !root->right){
                if(value == expectNumber){
                    output.push_back(vector<int>({value}));
                }
            }else {
                if(root->left){
                    vector<vector<int> > left = FindPath(root->left, expectNumber - value);
                    if (left.size() > 0) {
                        for (int i = 0; i < left.size(); ++i) {
                            left[i].insert(left[i].begin(), 1, value);
                            output.push_back(left[i]);
                        }
                    }
                }
                if(root->right){
                    vector<vector<int> > right = FindPath(root->right, expectNumber - value);
                    if (right.size() > 0) {
                        for (int j = 0; j < right.size(); ++j) {
                            right[j].insert(right[j].begin(), 1, value);
                            output.push_back(right[j]);
                        }
                    }
                }
            }
        }
        return output;
    }
};