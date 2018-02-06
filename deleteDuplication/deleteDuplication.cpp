//
// Created by Qiezz on 18-2-4.
//
#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = pHead;
        if(pHead){
            ListNode* a = sentinel, *b = pHead->next;
            while (b){
                if(a->next->val == b->val){
                    while(b && a->next->val == b->val){
                        b = b->next;
                    }
                    a->next = b;
                }else{
                    a = a->next;
                }
                if(b){
                    b = b->next;
                }
            }
        }
        return sentinel->next;
    }
};