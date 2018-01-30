//
// Created by Qiezz on 18-1-29.
//
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence_alter(int sum) {
        vector<vector<int> >output;
        vector<int> temp;
        int max = (int)sqrt(2 * sum);
        double quo;

        for (int i = max; i >= 2; i--) {
            quo = sum * 1.0 / i;
            if(i & 1){
                if((quo - (int)quo) == 0){
                    temp.clear();
                    for (int j = (int)quo - i/2; j <= (int)quo + i/2; ++j) {
                        temp.push_back(j);
                    }
                    output.push_back(temp);
                }
            }else{
                if(quo - (int)quo != 0 && quo*2 - (int)(quo*2) == 0){
                    temp.clear();
                    for (int j = (int)quo - i/2 + 1; j <= (int)quo + i/2; ++j) {
                        temp.push_back(j);
                    }
                    output.push_back(temp);
                }
            }
        }
        return output;
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        int left = 1;
        int right = 2;
        int cur = left + right;
        vector<vector<int> >output;
        vector<int> temp;
        while(left < (1 + sum)/2){
            if(cur == sum){
                temp.clear();
                for (int i = left; i <= right; ++i) {
                    temp.push_back(i);
                }
                output.push_back(temp);
                cur -= left;
                left ++;
            }else if(cur > sum){
                cur -= left;
                left ++;
            }else{
                right ++;
                cur += right;
            }
        }
        return output;
    }
};