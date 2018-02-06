//
// Created by Qiezz on 18-2-4.
//
#include <iostream>
#include <stack>
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
    vector<int> Serialize(TreeNode *root) {
        vector<int> buf;
        stack<TreeNode*> stack1;
        TreeNode* cur;
        if(root){
            buf.push_back(root->val);
            stack1.push(root);
            cur = root->left;
            while(cur || stack1.size()){
                if(cur){
                    buf.push_back(cur->val);
                    stack1.push(cur);
                    cur = cur->left;
                }else{
                    buf.push_back(-1);
                    cur = stack1.top();
                    stack1.pop();
                    cur = cur->right;
                }
            }
            buf.push_back(-1);
        }
        return buf;
    }
    TreeNode* Deserialize(vector<int> output) {
        int ind = 0;
        return rebuild(output, ind);
    }
    TreeNode* rebuild(vector<int> &output, int &ind){
        if(output[ind] == -1){
            return NULL;
        }
        TreeNode* node = new TreeNode(output[ind]);
        ind ++;
        node->left = rebuild(output, ind);
        ind ++;
        node->right = rebuild(output, ind);
        return node;
    }
};