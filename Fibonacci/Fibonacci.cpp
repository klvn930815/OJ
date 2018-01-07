//
// Created by Qiezz on 18-1-5.
//

class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 1) return n;
        int i = 2;
        long long fibo_left = 0;
        long long fibo_right = 1;
        long long fibo = 0;
        while(i <= n){
            fibo = fibo_left + fibo_right;
            fibo_left = fibo_right;
            fibo_right = fibo;
            i++;
        }
        return fibo;
    }
};