//
// Created by Qiezz on 18-1-30.
//

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() >= 5){
            sort(numbers.begin(), numbers.end());
            int zeroNum = 0;
            int i = 0;
            while(numbers[i] == 0 && i < numbers.size()){
                zeroNum ++;
                i++;
            }
            int diff, small = i, big = i + 1;
            while(big < numbers.size()){
                diff = numbers[big] - numbers[small];
                if(diff == 0){
                    return false;
                }
                if(diff > 1){
                    zeroNum -= (diff - 1);
                    if(zeroNum < 0){return false;}
                }
                big ++;
                small ++;
            }
            return true;
        }
        return false;
    }
};