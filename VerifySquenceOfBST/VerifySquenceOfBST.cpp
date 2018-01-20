//
// Created by Qiezz on 18-1-12.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0){
            return false;
        }
        if (sequence.size() == 1){
            return true;
        }
        int ind = 0;
        while (sequence[ind] < sequence[sequence.size() - 1]){
            ind ++;
        }
        for (int i = ind; i < sequence.size() - 1; ++i) {
            if(sequence[i] < sequence[sequence.size() - 1]){
                return false;
            }
        }
        bool left = true;
        bool right = true;
        if (ind > 0){
            left = VerifySquenceOfBST(vector<int>(sequence.begin(),sequence.begin() + ind));
        }
        if (ind < sequence.size() - 1){
            right = VerifySquenceOfBST(vector<int>(sequence.begin() + ind, sequence.end() - 1));
        }
        return left && right;
    }
};