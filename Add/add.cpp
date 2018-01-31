//
// Created by Qiezz on 18-1-31.
//

class Solution {
public:
    int Add(int num1, int num2)
    {
        int base = num1, carry;
        while(num2){
            base = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = base;
            num2 = carry;
        }
        return base;
    }
};