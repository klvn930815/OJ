//
// Created by Qiezz on 18-2-4.
//
#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> >output;
        if(pRoot){
            stack<TreeNode*> stacks[2];
            vector<int> values;
            TreeNode* cur;
            int next_forward = 0;
            stacks[1].push(pRoot);
            while(!stacks[0].empty() || !stacks[1].empty()){
                while(!stacks[!next_forward].empty()) {
                    cur = stacks[!next_forward].top();
                    stacks[!next_forward].pop();
                    values.push_back(cur->val);
                    if(next_forward){
                        if(cur->right){
                            stacks[1].push(cur->right);
                        }
                        if(cur->left){
                            stacks[1].push(cur->left);
                        }
                    }else{
                        if(cur->left){
                            stacks[0].push(cur->left);
                        }
                        if(cur->right){
                            stacks[0].push(cur->right);
                        }
                    }
                }
                output.push_back(values);
                values.clear();
                next_forward = !next_forward;
            }
        }
        return output;
    }

};