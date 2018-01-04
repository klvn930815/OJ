//
// Created by Qiezz on 18-1-3.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> output;
        if(head){
            output.push_back(head->val);
            ListNode* cur = head->next;
            while(cur){
                output.insert(output.begin(), cur->val);
                cur = cur->next;
            }
        }
        return output;
    }
};