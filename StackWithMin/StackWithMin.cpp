//
// Created by Qiezz on 18-1-12.
//
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        oriStack.push(value);
        if(minStack.empty()){
            minStack.push(value);
        }else{
            minStack.push(minStack.top() > value? value:minStack.top());
        }
    }
    void pop() {
        if(oriStack.empty()) return;
        oriStack.pop();
        minStack.pop();
    }
    int top() {
        return oriStack.top();
    }
    int min() {
        return minStack.top();
    }

private:
    stack<int> oriStack, minStack;

};