//
// Created by Qiezz on 18-1-25.
//
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n < 1){
            return 0;
        }
        string n_str = to_string(n);
        int length = int(n_str.size());
        if(length == 0){
            return 0;
        }
        int first_v = n_str[0] - '0';
        int num_first = 0, num_other = 0, n_sub = n % int(pow(10, length - 1));

        if(first_v > 1){
            num_first = int(pow(10, length - 1));
        }
        else{
            num_first = n_sub + 1;
        }
        num_other = first_v * int(pow(10, length - 2)) * (length - 1);
        return num_first + num_other + NumberOf1Between1AndN_Solution(n_sub);
    }
};