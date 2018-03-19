//
// Created by Qiezz on 18-3-19.
//

/* 题目:
 * 为了得到一个数的"相反数",我们将这个数的数字顺序颠倒,然后再加上原先的数得到"相反数"。
 * 例如,为了得到1325的"相反数",首先我们将该数的数字顺序颠倒,我们得到5231,
 * 之后再加上原先的数,我们得到5231+1325=6556.
 * 如果颠倒之后的数字有前缀零,前缀零将会被忽略。
 * 例如n = 100, 颠倒之后是1.
 *
 */

#include<iostream>
#include<sstream>
using namespace std;

int ReverseValue(int n){
    stringstream ss;
    ss<<n;
    string str_n = ss.str();
    int length = str_n.size();
    int re = 0, m = n;
    for (int i = 0; i < length; ++i) {
        re = re * 10 + m % 10;
        m /= 10;
    }
    return re + n;
}
