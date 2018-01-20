//
// Created by Qiezz on 18-1-12.
//

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> sta;
        int ind = 0;
        if(pushV.empty() || popV.empty() || pushV.size() != popV.size()) return false;
        for (int i = 0; i < pushV.size(); ++i) {
            sta.push(pushV[i]);
            while(ind < popV.size() && sta.top() == popV[ind]){
                sta.pop();
                ind ++;
            }
        }
        return sta.empty();
    }

};