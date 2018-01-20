//
// Created by Qiezz on 18-1-14.
//

#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *newHead=NULL, *cur=NULL, *fol=pHead;
        if(pHead){
            while(fol){
                cur = fol;
                fol = cur->next;
                cur->next = new RandomListNode(cur->label);
                cur->next->next = fol;
            }
            cur = pHead;
            while(cur){
                fol = cur->next;
                if(cur->random){
                    fol->random = cur->random->next;
                }
                cur = cur->next->next;
            }
            newHead = pHead->next;
            pHead->next = newHead->next;
            fol = newHead;
            cur = fol->next;
            while (cur){
                fol->next = cur->next;
                fol = fol->next;
                cur->next = fol->next;
                cur = cur->next;
            }
        }
        return newHead;
    }
};