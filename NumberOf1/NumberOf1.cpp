//
// Created by Qiezz on 18-1-7.
//

class Solution {
public:
    int NumberOf1_normal(int n) {
        unsigned int i = 1;
        int times = 0;
        int count = 0;
        while(i){
            if (n & i){
                count ++;
            }
            i = i << 1;
            times ++;
        }
        return count;
    }

    int NumberOf1(int n) {
        int count = 0;
        while(n){
            n = n&(n-1);
            count ++;
        }
        return count;
    }

};