//
// Created by Qiezz on 18-2-2.
//

#include <iostream>

class Solution {
public:
    bool match(char* str, char* pattern) {
        if(str == NULL || pattern == NULL){
            return false;
        }
        return matchcore(str, pattern);
    }
    bool matchcore(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0'){
            return true;
        }
        if(*str != '\0' && *pattern == '\0'){
            return false;
        }
        if(*(pattern + 1) == '*'){
            if(*str == *pattern || (*str != '\0' && *pattern == '.')){
                return matchcore(str + 1, pattern + 2) ||
                       matchcore(str + 1, pattern) ||
                       matchcore(str, pattern + 2);
            }
            return matchcore(str, pattern + 2);
        }
        if(*str == *pattern || (*str != '\0' && *pattern == '.')){
            return matchcore(str + 1, pattern + 1);
        }
        return false;
    }
};