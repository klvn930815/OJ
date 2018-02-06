//
// Created by Qiezz on 18-2-5.
//
#include <iostream>
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
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        TreeNode* output;
        int ind = 0;
        stack<TreeNode*> stack1;
        if(pRoot && k){
            output = pRoot;
            while(output || stack1.size()){
                if(output){
                    stack1.push(output);
                    output = output->right;
                }else{
                    ind ++;
                    output = stack1.top();
                    stack1.pop();
                    if(ind == k){
                        return output;
                    }
                    output = output->left;
                }
            }
            return NULL;
        }
        return NULL;
    }

};