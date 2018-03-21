//
// Created by Qiezz on 18-3-21.
//

/*
 * 实现大数乘法
 *
 * 就是实现手算乘法的步骤，用vector记录结果的每一位，然后要从低位到高位处理进位的情况。
 */

#include<iostream>
#include<vector>

using namespace std;

void multi(string str1, string str2) {
    int i, j, len;
    bool flag = false;
    bool positive = true;

    if (str1[0] == '-') {// 判断正负，然后去掉符号
        str1.erase(0, 1);
        positive = !positive;
    }
    if (str2[0] == '-') {
        str2.erase(0, 1);
        positive = !positive;
    }
    vector<int> a(str1.size(), 0), b(str2.size(), 0);
    len = str1.size() * str2.size() + 1;
    vector<int> output(len, 0);

    for (i = 0; i < str1.size(); i++) {//数组从低位到高位存储每一位数字
        a[i] = str1[str1.size() - 1 - i] - '0';
    }

    for (i = 0; i < str2.size(); i++) {
        b[i] = str2[str2.size() - 1 - i] - '0';
    }

    if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0)) {
        cout << "0" << endl;
        return;
    }
    for (i = 0; i < str1.size(); i++)  //逐位相乘
    {
        for (j = 0; j < str2.size(); j++)
            output[i + j] += a[i] * b[j];
    }
    for (i = 0; i < len; i++)   //处理进位的情况
    {
        if (output[i] > 9) {
            output[i + 1] += output[i] / 10;
            output[i] %= 10;
        }
    }
    if (!positive) {
        cout << "-";
    }
    for (i = len - 1; i >= 0; i--) {
        if (flag) // 判断找到第一位非0
            cout << output[i];
        else if (output[i] != 0) {
            cout << output[i];
            flag = true;
        }
    }
    cout << endl;
    return;
}