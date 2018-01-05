//
// Created by Qiezz on 18-1-5.
//
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()){
            return 0;
        }
        if(rotateArray.size() > 1){
            for (int i = rotateArray.size() - 1; i > 0; --i) {
                if(rotateArray.at(i) < rotateArray.at(i - 1)){
                    return rotateArray.at(i);
                }
            }
        }
        return rotateArray.at(0);
    }

    int minNumberInRotateArray_alter(vector<int> rotateArray) {
        if (rotateArray.empty()){
            return 0;
        }
        int mid = 0;
        if(rotateArray.size() > 1){
            int right = rotateArray.size() - 1;
            int left = 0;
            while(left < right){
                mid = (left + right) / 2;
                if (rotateArray[mid] > rotateArray[right]){
                    left = mid + 1;
                }else if(rotateArray[mid] == rotateArray[right]){
                    right = mid - 1;
                }else{
                    right = mid;
                }
            }
            return rotateArray[left];
        }
        return rotateArray[mid];
    }
};