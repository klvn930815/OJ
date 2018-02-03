//
// Created by Qiezz on 18-2-3.
//
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if(times.find(ch) == times.end()){
            times.insert(pair<char, int>(ch, 1));
            orders.push_back(ch);
        }else{
            times[ch] += 1;
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(orders.size() > 0 && times[*(orders.begin())] > 1){
            orders.pop_front();
        }
        if(orders.size() > 0){
            return *(orders.begin());
        }else{
            return '#';
        }
    }
private:
    list<char> orders;
    unordered_map<char, int> times;
};