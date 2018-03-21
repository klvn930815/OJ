//
// Created by Qiezz on 18-3-21.
//

#include<iostream>
using namespace std;

/*
 * 在字符串里找到最长的连续数字串
 *
 */

void longestNumerics(string str) {
    int maxLen = 0, len;
    string output, tmp;

    for (int i = 0; i < str.size(); i++) {
        len = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            tmp += str[i];
            len++;
            i++;
        }
        if (len >= maxLen) {
            maxLen = len;
            output = tmp;
        }
        tmp.clear();
    }
    cout << output << "," << maxLen << endl;
}