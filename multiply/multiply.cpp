//
// Created by Qiezz on 18-2-1.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> B(len, 1), C(len, 1), D(len, 1);
        for (int i = 1; i < len; ++i) {
            C[i] = C[i-1] * A[i-1];
        }
        for (int i = len - 2; i >= 0; --i) {
            D[i] = D[i+1] * A[i+1];
        }
        for (int j = 0; j < len; ++j) {
            B[j] = C[j] * D[j];
        }
        return B;
    }
};