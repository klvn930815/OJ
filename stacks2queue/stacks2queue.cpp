//
// Created by Qiezz on 18-1-4.
//
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        int temp;
        if(!stack2.empty()){
            while (!stack1.empty()){
                stack1.pop();
            }
            while (!stack2.empty()){
                temp = stack2.top();
                stack1.push(temp);
                stack2.pop();
            }
        }
        stack1.push(node);
    }

    int pop() {
        int node;
        if(!stack1.empty()){
            while (!stack2.empty()){
                stack2.pop();
            }
            while (!stack1.empty()){
                node = stack1.top();
                stack2.push(node);
                stack1.pop();
            }
        }
        node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};