//
// Created by Qiezz on 18-2-4.
//

#include <iostream>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode) return pNode;
        TreeLinkNode *output = NULL;
        if(pNode->right){
            output = pNode->right;
            while(output->left){
                output = output->left;
            }
        }else{
            while(pNode->next && pNode->next->right == pNode){
                pNode = pNode->next;
            }
            output = pNode->next;
        }
        return output;
    }
};