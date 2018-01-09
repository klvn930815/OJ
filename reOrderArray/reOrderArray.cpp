//
// Created by Qiezz on 18-1-9.
//
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd, even;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] & 1){
                odd.push_back(array[i]);
            }else{
                even.push_back(array[i]);
            }
        }
        array.clear();
        array.insert(array.end(), odd.begin(), odd.end());
        array.insert(array.end(), even.begin(), even.end());
    }
};