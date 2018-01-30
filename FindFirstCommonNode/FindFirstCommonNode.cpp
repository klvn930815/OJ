//
// Created by Qiezz on 18-1-28.
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL){
            return NULL;
        }
        int len_1 = 0, len_2 = 0;
        ListNode* cur_1 = pHead1, *cur_2 = pHead2;
        while(cur_1){
            cur_1 = cur_1->next;
            len_1++;
        }
        while(cur_2){
            cur_2 = cur_2->next;
            len_2++;
        }
        cur_1 = pHead1;
        cur_2 = pHead2;
        int cur_dist = 0;
        int dist = abs(len_2 - len_1);
        if(len_2 > len_1){
            while(cur_dist < dist){
                cur_2 = cur_2->next;
                cur_dist++;
            }
        }else if(len_1 > len_2){
            while(cur_dist < dist){
                cur_1 = cur_1->next;
                cur_dist++;
            }
        }
        while(cur_1 && cur_2){
            if(cur_1 == cur_2){
                return cur_1;
            }else{
                cur_1 = cur_1->next;
                cur_2 = cur_2->next;
            }
        }
        return NULL;
    }
};