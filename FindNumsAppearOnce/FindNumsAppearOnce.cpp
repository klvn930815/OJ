//
// Created by Qiezz on 18-1-29.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) {
        if(data.size() < 2){
            return;
        }
        int xo = 0;
        for(auto a: data){
            xo ^= a;
        }
        int thresh = (xo&(xo-1))^xo;
        *num1 = *num2 = 0;
        for(auto a:data){
            if(a & thresh){
                *num1 ^= a;
            }else{
                *num2 ^= a;
            }
        }
    }
};