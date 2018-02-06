//
// Created by Qiezz on 18-2-5.
//

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void Insert(int num) {
        if(head.empty() || head.top() > num){
            head.push(num);
        }else{
            tail.push(num);
        }
        if(head.size() - tail.size() == 2){
            tail.push(head.top());
            head.pop();
        }
        if(tail.size() - head.size() == 1){
            head.push(tail.top());
            tail.pop();
        }
    }

    double GetMedian()
    {
        if(head.size() > tail.size()){
            return head.top();
        }
        else{
            return head.top()*0.5 + tail.top()*0.5;
        }
    }

private:
    priority_queue<int> head;
    priority_queue<int, vector<int>, greater_equal<int>> tail;

};