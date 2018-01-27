//
// Created by Qiezz on 18-1-24.
//
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int, greater<int> > buf;
        vector<int> output;
        buf.clear();
        if (k > 0 && input.size() >= k) {
            for (auto v : input) {
                if (buf.size() < k) {
                    buf.insert(v);
                } else if (*buf.begin() > v) {
                    buf.erase(buf.begin());
                    buf.insert(v);
                }
            }
        }
        output.assign(buf.begin(), buf.end());
        return output;
    }
};


