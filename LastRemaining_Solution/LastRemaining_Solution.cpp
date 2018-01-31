//
// Created by Qiezz on 18-1-30.
//

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1){
            return -1;
        }
        int ans = 0;
        for (int i = 2; i <= n ; ++i) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};