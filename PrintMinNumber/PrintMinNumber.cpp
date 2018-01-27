//
// Created by Qiezz on 18-1-26.
//
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size() == 0){
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);
        string output;
        for(auto a: numbers){
            output.append(to_string(a));
        }
        return output;

    }
    static bool cmp(int a, int b){
        string left = to_string(a) + to_string(b);
        string right = to_string(b) + to_string(a);
        return left < right;
    }
};