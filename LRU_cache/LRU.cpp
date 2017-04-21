#include "LRU.h"

int LRUCache::get(int key) {
    auto ite = data.find(key);
    // not find
    if (ite == data.end()) {
        return -1;
    }

    order.erase(ite->second.second);
    order.push_front(key);
    ite->second.second = order.begin();
    return ite->second.first;
}

void LRUCache::put(int key, int value) {
    auto ite = data.find(key);
    //new key
    if (ite == data.end()) {
        if (data.size() == capacity) {
            data.erase(order.back());
            order.pop_back();
        }
    } else {
        order.erase(ite->second.second);
    }
    order.push_front(key);
    data[key] = make_pair(value, order.begin());
}