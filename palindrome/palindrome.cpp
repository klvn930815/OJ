//
// Created by Qiezz on 17-8-2.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        long max = pow(2, 31);
        long mindis = max;
        long ans;
        int len = n.size();
        long src = stol(n);
        vector<long>candidates;
        candidates.push_back((long)pow(10, len-1)-1);
        candidates.push_back((long)pow(10, len)+1);

        string pre = n.substr(0, (len + 1)/2);
        for (int i = -1; i < 2; ++i) {
            string ppre = to_string(stol(pre) + i);
            string candi = ppre + string(ppre.rbegin() + (len & 1), ppre.rend());
            candidates.push_back(stol(candi));
        }
        vector<long>::iterator toDel = find(candidates.begin(), candidates.end(), stol(n));
        while (toDel != candidates.end()) {
            candidates.erase(toDel);
            toDel = find(candidates.begin(), candidates.end(), stol(n));
        }
        for(auto ite: candidates){
            if (mindis > abs(ite - src)){
                mindis = abs(ite - src);
                ans = ite;
            }
        }
        return to_string(ans);
    }
};