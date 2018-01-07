//
// Created by Qiezz on 18-1-5.
//

#include <math.h>

class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 1) return 1;
        return pow(2, number - 1);
    }
};