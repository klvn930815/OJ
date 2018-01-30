//
// Created by Qiezz on 18-1-28.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0){
            return 0;
        }
        int left = GetFirstK(data, 0, data.size() - 1, k);
        if(left == -1){return 0;}
        int right = GetLastK(data, 0, data.size() - 1, k);
        return right - left + 1;
    }
    int GetFirstK(vector<int>& data, int start, int end, int k){
        if(end - start <= 1){
            if(data[start] == k){
                return start;
            }
            if(data[end] == k){
                return end;
            }
            return -1;
        }
        int mid = start + (end - start)/2;
        if(data[mid] > k){
            return GetFirstK(data, start, mid - 1, k);
        }else if(data[mid] < k){
            return GetFirstK(data, mid + 1, end, k);
        }else if(data[mid - 1] != k){
            return mid;
        }else{
            return GetFirstK(data, start, mid - 1, k);
        }
    }
    int GetLastK(vector<int>& data, int start, int end, int k){
        if(end - start <= 1){
            if(data[end] == k){
                return end;
            }
            if(data[start] == k){
                return start;
            }
            return -1;
        }
        int mid = start + (end - start)/2;
        if(data[mid] > k){
            return GetLastK(data, start, mid - 1, k);
        }else if(data[mid] < k){
            return GetLastK(data, mid + 1, end, k);
        }else if(data[mid + 1] != k){
            return mid;
        }else{
            return GetLastK(data, mid + 1, end, k);
        }
    }




};