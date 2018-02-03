//
// Created by Qiezz on 18-2-2.
//
#include <iostream>

class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == NULL || *string == '\0'){
            return false;
        }
        char* cur = string;
        // . ?  +-. ?
        bool e_ava = true, dot_ava = true, first = true;
        while(*cur != '\0'){
            if(*cur == '.'){
                if(dot_ava && e_ava){
                    dot_ava = false;
                }else{
                    return false;
                }
            }else if(*cur == 'e' || *cur == 'E'){
                if(e_ava && *(cur + 1) != '\0' && *(cur - 1) - '0' >= 0 && *(cur - 1) - '0' <= 9){
                    e_ava = false;
                }else{
                    return false;
                }
            }else if(*cur == '+' || *cur == '-'){
                if(*(cur + 1) == '\0'){
                    return false;
                }
                if(!first){
                    if(*(cur - 1) != 'e' && *(cur - 1) != 'E'){
                        return false;
                    }
                }
            }else if(*cur - '0' < 0 || *cur - '0' > 9 ){
                return false;
            }
            cur ++;
            first = false;
        }
        return true;
    }
};

