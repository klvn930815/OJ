//
// Created by Qiezz on 18-1-21.
//
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> output;
        if(str.size() > 0){
            if (str.size() == 1){
                output.push_back(str);
            }else{
                unordered_set<char> buf;

                for (int i = 0; i < str.size(); ++i) {
                    if(buf.find(str[i]) == buf.end()){
                        buf.insert(str[i]);
                        char temp = str[i];
                        vector<string> part;
                        str[i] = str[0];
                        str[0] = temp;
                        part = Permutation(str.substr(1));
                        for (int j = 0; j < part.size(); ++j) {
                            part[j].insert(part[j].begin(), str[0]);
                        }
                        output.insert(output.end(), part.begin(), part.end());
//                        temp = str[i];
//                        str[i] = str[0];
//                        str[0] = temp;

                    }
                }
            }
        }
        return output;
    }
};