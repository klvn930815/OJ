//
// Created by Qiezz on 18-1-27.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() <= 1){
            return 0;
        }
        long long inv_num = 0;
        vector<int> output(data.size(), 0);
        int ind, length = 1;
        while (length <= data.size()){
            ind = 0;
            while(ind + 2 * length <= data.size()){
                inv_num += Merge(data, output, ind, ind + length - 1, ind + 2 * length -1);
                ind += 2 * length;
            }
            if(ind + length <= data.size()){
                inv_num += Merge(data, output, ind, ind + length - 1, data.size() - 1);
            }
            data.swap(output);
            length *= 2;
        }
        return (int)(inv_num % 1000000007);
    }
    long long Merge(vector<int> &data, vector<int> &output, int start, int mid, int end){
        long long num = 0;
        int ind = end;
        int i = mid, j = end;
        while (i >= start && j >= mid + 1) {
            if(data[i] <= data[j]){
                output[ind--] = data[j--];
            }else{
                output[ind--] = data[i--];
                num += (j - mid);
            }
        }
        while(i >= start){
            output[ind--] = data[i--];
        }
        while(j >= mid + 1){
            output[ind--] = data[j--];
        }
        return num;
    }

};