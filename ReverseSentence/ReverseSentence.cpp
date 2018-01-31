//
// Created by Qiezz on 18-1-30.
//
#include <string>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.size();
        if(len > 0){
            rotate(str, 0, len - 1);
            int left = 0, right = 0;
            while(right < len){
                if(right == len - 1){
                    rotate(str, left, right);
                }else if(str[right] == ' '){
                    rotate(str, left, right - 1);
                    left = right + 1;
                }
                right ++;
            }
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