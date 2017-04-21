#ifndef OJ_LRU_H
#define OJ_LRU_H

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> order;
    unordered_map<int,pair<int,list<int>::iterator>> data;

public:
    LRUCache(int capacity):capacity(capacity) {}
    int get(int key);
    void put(int key, int value);
};
#endif //OJ_LRU_H
