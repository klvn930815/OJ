//
// Created by Qiezz on 18-1-11.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> output;
        if(matrix.size() == 0 || matrix[0].size() == 0)return output;

        vector<int> bound = {(int)matrix.size() - 1, (int)matrix[0].size() - 1};
        for(int i = 0; i <= bound[1]; i++){
            output.push_back(matrix[0][i]);
        }
        vector<int> cur = {0, bound[1]};
        vector<int> add = {1, -1};
        int turn = 0;
        
        while(bound[turn] > 0){
            for(int j = 1; j <= bound[turn]; j++){
                cur[turn] += add[turn];
                output.push_back(matrix[cur[0]][cur[1]]);
            }
            bound[turn] --;
            add[turn] *= -1;
            turn = (turn > 0 ? 0 : 1);
        }
        return output;
    }
};