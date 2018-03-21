//
// Created by Qiezz on 18-3-21.
//


/*
 * 根据数值占用BIT数，按顺序从输入字节流中解析出对应数值，解析顺序按输入数组astElement索引升序
 *
 * 输入:
 * 字节数组长度uiIutputLen为2；
 * 字节数组aInputByte[2]为{0x62, 0x80}，对应二进制为“01100010 1 000 0000”；
 * 解析数值个数uiElementNum为2；
 * 数值[0]的值占4个bit，即astElement[0].uiElementLength = 4；
 * 数值[1]的值占5个bit，即astElement[1].uiElementLength = 5；
 *
 * 输出：
 * 数值[0]的值为6，二进制为“0110”，即astElement[0].uiElementValue = 6；
 * 数值[1]的值为5，二进制为“0010 1”，即astElement[1].uiElementValue = 5。
 *
 * 这题要注意的细节就是cin>>hex>>input[i]节省时间，然后就是注意结果的范围比较大，要用long long装
 */

#include <iostream>
#include <vector>

using namespace std;


void Decode(vector<int> inputs, vector<int> bitnums) {
    vector<bool> bitstream;
    for (int i = 0; i < inputs.size(); ++i) {
        for (int j = 0x80; j > 0; j >>= 1) {
            bitstream.push_back(inputs[i] & j);// 获取字节流
        }
    }
    long long output = 0;
    int start = 0;
    for (int k = 0; k < bitnums.size(); ++k) {
        for (int i = 0; i < bitnums[k]; ++i) {
            output = output * 2 + bitstream[i + start];
        }
        cout << output << endl;
        start += bitnums[k];
        output = 0;
    }
    return;
}

int main() {
    int total, first, int_tmp;
    vector<int> inputs;
    vector<int> bitnums;
    while (cin >> total) {
        for (int i = 0; i < total; ++i) {
            cin >> hex >> int_tmp;
            inputs.push_back(int_tmp);
        }
        cin >> dec >> first;
        for (int j = 0; j < first; ++j) {
            cin >> int_tmp;
            bitnums.push_back(int_tmp);
        }
        Decode(inputs, bitnums);
    }
}
