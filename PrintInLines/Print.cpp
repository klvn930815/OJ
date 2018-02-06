//
// Created by Qiezz on 18-2-4.
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > output;
        if(pRoot){
            queue<TreeNode* > queues[2];
            vector<int> values;
            TreeNode* node;
            int cur_layer = 0;
            queues[0].push(pRoot);
            while(queues[0].size() || queues[1].size()){
                while(queues[cur_layer].size()){
                    node = queues[cur_layer].front();
                    queues[cur_layer].pop();
                    values.push_back(node->val);
                    if(node->left){
                        queues[!cur_layer].push(node->left);
                    }
                    if(node->right){
                        queues[!cur_layer].push(node->right);
                    }
                }
                cur_layer = !cur_layer;
                output.push_back(values);
                values.clear();
            }
        }
        return output;
    }
};