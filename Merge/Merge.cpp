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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1)    return pHead2;
        if (!pHead2)    return pHead1;

        ListNode *sentinel = new ListNode(-1);
        sentinel->next = pHead1;
        ListNode *cur1 = sentinel, *cur2 = pHead2, *fol2 = pHead2->next;
        while(cur2 && cur1->next){
            while(cur1->next && cur1->next->val < cur2->val){
                cur1 = cur1->next;
            }
            if(cur1->next){
                fol2 = cur2->next;
                cur2->next = cur1->next;
                cur1->next = cur2;
                cur2 = fol2;
                cur1 = cur1->next;
            }
        }
        if(cur2){
            cur1->next = cur2;
        }
        return sentinel->next;
    }

    ListNode* Merge_Recursion(ListNode* pHead1, ListNode* pHead2){
        if (!pHead1)    return pHead2;
        if (!pHead2)    return pHead1;
        ListNode* newHead;
        if(pHead1->val > pHead2->val){
            newHead = pHead2;
            newHead->next = Merge_Recursion(pHead1, pHead2->next);
        }
        else{
            newHead = pHead1;
            newHead->next = Merge_Recursion(pHead1->next, pHead2);
        }
        return newHead;
    }
    ListNode* Merge_2(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *nil1 = new ListNode(999);
        nil1->next = pHead1;
        ListNode* pre = nil1, *cur1 = pHead1, *cur2 = pHead2;
        while(cur1 && cur2){
            if(cur2->val < cur1->val){
                pre->next = cur2;
                cur2 = cur2->next;
                pre->next->next = cur1;
            }
            else{
                cur1 = cur1->next;
            }
            pre = pre->next;
        }
        if(cur2){
            pre->next = cur2;
        }
        return nil1->next;
    }
};