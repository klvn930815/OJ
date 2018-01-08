//
// Created by Qiezz on 18-1-8.
//

class Solution {
public:
    double Power(double base, int exponent) {
        bool Isnegative = false;
        int bound = 1;
        double output = 1.0;
        double mid = base;
        if(exponent < 0){
            Isnegative = true;
            exponent = -exponent;
        }
        while(bound <= exponent){
            if (bound & exponent){
                output *= mid;
            }
            mid *= mid;
            bound = bound << 1;
        }
        if(Isnegative){
            output = 1/output;
        }
        return output;
    }
};