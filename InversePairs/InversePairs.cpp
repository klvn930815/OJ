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
        vector<int> output(data);
        int ind, length = 1;
        int inv_num = MergeSort(data, output, 0, data.size() - 1);
        return inv_num % 1000000007;
    }
    int MergeSort(vector<int> &data, vector<int> &output, int start, int end){
        if(end > start){
            int mid = start + (end - start) / 2;
            int left = MergeSort(data, output, start, mid), right = MergeSort(data, output, mid + 1, end);
            return (Merge(data, output, start, mid, end) + left + right) % 1000000007;
        }
        return 0;
    }
    int Merge(vector<int> &data, vector<int> &output, int start, int mid, int end){
        int num = 0;
        int ind = end;
        int i = mid, j = end;
        // 从尾部开始
        while (i >= start && j >= mid + 1) {
            if(data[i] <= data[j]){
                output[ind--] = data[j--];
            }else{
                output[ind--] = data[i--];
                num += (j - mid);
                if(num >= 1000000007){
                    num %= 1000000007;
                }
            }
        }
        while(i >= start){
            output[ind--] = data[i--];
        }
        while(j >= mid + 1){
            output[ind--] = data[j--];
        }
        for (int k = start; k <= end; ++k) {
            data[k] = output[k];
        }
        return num % 1000000007;
    }
};