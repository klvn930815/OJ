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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead){
            return NULL;
        }
        ListNode *fast = pHead, *slow = pHead;
        int steps = 0, meet_steps = 0, len = -1;
        while (len == -1){
            if(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            } else{
                return NULL;
            }
            steps ++;
            if(slow == fast){
                if(meet_steps){
                    len = steps - meet_steps;
                }else{
                    meet_steps = steps;
                }
            }
        }
        fast = pHead;
        slow = pHead;
        steps = 0;
        while(steps < len){
            steps++;
            fast = fast->next;
        }
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};