//
// Created by Qiezz on 18-1-21.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0){
            return 0;
        }
        if (numbers.size() == 1) {
            return numbers[0];
        }
        int start = 0, end = numbers.size();
        int target = end >> 1;
        int ind = partition(numbers, start, end);
        while(ind != target){
            if(ind > target){
                start = ind + 1;
            }else{
                end = ind - 1;
            }
            ind = partition(numbers, start, end);
        }
        return numbers[ind];
    }

    int partition(vector<int> &numbers, int start, int end){
        int ind = (rand() % (end - start + 1)) + start;
        int bound = numbers[ind];
        swap(numbers[start], numbers[ind]);
        int low = start, high = end;
        while (low < high){
            while(numbers[high] >= bound && low < high){
                high --;
            }
            swap(numbers[low], numbers[high]);
            while(numbers[low] < bound && low < high){
                low ++;
            }
            swap(numbers[low], numbers[high]);
        }
        swap(numbers[start], numbers[low]);
        return low;
    }
    int MoreThanHalfNum_Solution_alter(vector<int> numbers){
        if (numbers.size() == 0){
            return 0;
        }
        int cur_num = -1;
        int times = -1;
        for(auto a : numbers){
            if (times == -1){
                cur_num = a;
                times = 1;
            }else{
                if (cur_num == a){
                    times ++;
                }else if (times > 0){
                    times --;
                }else{
                    cur_num = a;
                    times = 1;
                }
            }
        }
        cur_num = CheckTimes(numbers, cur_num);
        return cur_num;
    }
    int CheckTimes(vector<int> numbers, int candidate){
        int times = 0;
        for(auto i : numbers){
            if(i == candidate){
                times ++;
            }
        }
        if(times * 2 <= numbers.size()){
            return 0;
        }else{
            return candidate;
        }
    }
};