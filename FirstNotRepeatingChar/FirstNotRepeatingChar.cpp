//
// Created by Qiezz on 18-1-27.
//
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0){
            return -1;
        }
        unordered_map<char, int> times;
        unordered_map<char, int>::iterator ite;
        for(auto s: str){
            ite = times.find(s);
            if(ite != times.end()){
                times[s] ++;
            }else{
                times.insert(pair<char, int>(s, 1));
            }
        }
        for(int ind = 0; ind < str.size(); ind ++){
            ite = times.find(str[ind]);
            if(ite->second == 1){
                return ind;
            }
        }
        return -1;
    }
};