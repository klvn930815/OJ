//
// Created by Qiezz on 18-3-19.
//

/* 题目：
 * 一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。
 * 例如,"aaabbaaac"是由下面碎片组成的:'aaa','bb','c'。
 * 牛牛现在给定一个字符串,请你帮助计算这个字符串的所有碎片的平均长度是多少。
 *
 */
#include<iostream>

using namespace std;

void FragileNum(string s, int n) {
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            count++;
        }
    }
    printf("%0.2f", (float) n / count);
}