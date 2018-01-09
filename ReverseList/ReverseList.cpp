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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre, *cur, *fol;
        if (!pHead || !pHead->next){
            return pHead;
        }
        pre = pHead;
        cur = pHead->next;
        pre->next = NULL;

        while(cur){
            fol = cur->next;
            cur->next = pre;
            pre = cur;
            cur = fol;
        }
        return pre;
    }
};