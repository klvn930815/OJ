//
// Created by Qiezz on 18-1-30.
//
#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(n > 0 && len > 0){
            n = n % len;
            rotate(str, 0, n-1);
            rotate(str, n, len-1);
            rotate(str, 0, len-1);
        }
        return str;
    }
    void rotate(string & str, int start, int end){
        int left = start, right = end;
        while(left < right){
            swap(str[left++], str[right--]);
        }
    }
};