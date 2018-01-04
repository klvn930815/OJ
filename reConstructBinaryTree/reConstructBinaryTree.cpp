//
// Created by Qiezz on 18-1-3.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* root;
        if (!pre.empty() && !vin.empty()){
            root = setTreeNode(pre, vin);
        }
        return root;
    }
    TreeNode* setTreeNode(vector<int> pre, vector<int> vin){
        TreeNode* root = new TreeNode(pre[0]);
        cout<<pre[0]<<endl;

        vector<int>::iterator pos = std::find(vin.begin(), vin.end(), pre[0]);
        if (pos != vin.begin()){
            root->left = setTreeNode(vector<int>(pre.begin() + 1, pre.begin() + 1 + (pos - vin.begin())), vector<int>(vin.begin(), pos));
        }
        if (pos != vin.end() - 1){
            root->right = setTreeNode(vector<int>(pre.end() - (vin.end() - pos) + 1, pre.end()), vector<int>(pos + 1, vin.end()));
        }
        return root;
    }

};