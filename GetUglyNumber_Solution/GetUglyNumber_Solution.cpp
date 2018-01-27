//
// Created by Qiezz on 18-1-26.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index ==0){
            return 0;
        }
        vector<int> buf;
        buf.push_back(1);
        int ugly_2_ind = 0, ugly_3_ind = 0, ugly_5_ind = 0;
        int cur_ind = 1;
        int next_ugly = buf[0];
        while (cur_ind < index){
            next_ugly = min(buf[ugly_2_ind] * 2, buf[ugly_3_ind] * 3);
            next_ugly = min(next_ugly, buf[ugly_5_ind] * 5);
            buf.push_back(next_ugly);
            while (buf[ugly_2_ind] * 2 <= next_ugly){
                ugly_2_ind ++ ;
            }
            while (buf[ugly_3_ind] * 3 <= next_ugly){
                ugly_3_ind ++ ;
            }
            while (buf[ugly_5_ind] * 5 <= next_ugly){
                ugly_5_ind ++ ;
            }
            cur_ind ++;
        }
        return next_ugly;
    }
};