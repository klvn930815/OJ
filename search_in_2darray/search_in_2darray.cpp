//
// Created by Qiezz on 18-1-1.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int len = array.size();
        if (len && array[0].size()){
            int y = 0;
            int x = len - 1;
            while(y <= array[x].size() - 1 && 0 <= x){
                if(array[x][y] < target){
                    y++;
                } else if (array[x][y] > target) {
                    x--;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};