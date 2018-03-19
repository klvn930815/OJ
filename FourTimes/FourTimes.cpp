//
// Created by Qiezz on 18-3-19.
//

/* 题目:
 * 小易有一个长度为N的正整数数列A = {A[1], A[2], A[3]..., A[N]}。
 * 牛博士给小易出了一个难题:
 * 对数列A进行重新排列,使数列A满足所有的A[i] * A[i + 1](1 ≤ i ≤ N - 1)都是4的倍数。
 * 小易现在需要判断一个数列是否可以重排之后满足牛博士的要求。
 *
 * 思路：
 * 满足上述条件的前提是
 * 1. 如果没有不被4整除的偶数，那么被4整除的数要不少于奇数-1
 * 2. 如果有不被4整除的偶数，那么被4整除的数要不少于奇数
 */

#include<iostream>
#include<vector>
using namespace std;

bool FourTimes(vector<int> array){
    int num_ftimes = 0, num_odd = 0;
    bool s_even = false;

    for(auto a: array){
        if((a & 1) != 0){
            num_odd += 1;
        }else{
            if((a & 3) == 0){
                num_ftimes += 1;
            }else{
                s_even = true;
            }
        }
    }
    return (num_ftimes >= num_odd && s_even) || (num_ftimes + 1 >= num_odd && !s_even);
}