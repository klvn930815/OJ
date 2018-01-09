//
// Created by Qiezz on 18-1-9.
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* a = pListHead;
        ListNode* b = pListHead;
        if (k < 1 || !pListHead) return NULL;
        int dist = 0;
        while(dist < k - 1) {
            dist++;
            if (a->next) {
                a = a->next;
            } else {
                return NULL;
            }
        }
        while(a->next){
            a = a->next;
            b = b->next;
        }
        return b;

    }
};