//
// Created by Qiezz on 18-2-5.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<int> max;
        vector<int> output;
        if(!num.empty() && size && num.size() >= size){
            for (int i = 0; i < num.size(); ++i) {
                if(!max.empty()){
                    if(i - max.front() >= size){
                        max.pop_front();
                    }
                    while(!max.empty() && num[max.back()] < num[i]){
                        max.pop_back();
                    }
                }
                max.push_back(i);
                if(i >= size - 1){
                    output.push_back(num[max.front()]);
                }
            }
        }
        return output;
    }
};