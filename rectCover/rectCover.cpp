//
// Created by Qiezz on 18-1-7.
//

class Solution {
public:
    int rectCover(int number) {
        //f(n) = f(n-1) + f(n-2)
        //f(1) = 1, f(2) = 2
        if (number <= 2){return number;}
        int left = 1;
        int right = 2;
        int output = -1;
        for (int i = 3; i <= number; ++i) {
            output = left + right;
            left = right;
            right = output;
        }
        return output;
    }
};