//
// Created by Qiezz on 18-1-30.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> output;
        if(array.size() > 1) {
            vector<int>::iterator left = array.begin(), right = array.end() - 1;
            while (left < right) {
                if (*left + *right > sum) {
                    right--;
                } else if (*left + *right < sum) {
                    left++;
                } else {
                    output.push_back(*left);
                    output.push_back(*right);
                    break;
                }
            }
        }
        return output;
    }
};