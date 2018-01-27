//
// Created by Qiezz on 18-1-25.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = 0, sum = 0;
        if (array.size() > 0){
            max = INT_MIN;
            for (int i = 0; i < array.size(); ++i) {
                if(sum <= 0){
                    sum = array[i];
                }else{
                    sum += array[i];
                }
                if(max < sum){
                    max = sum;
                }
            }
        }
        return max;
    }
};