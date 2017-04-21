#include "Max_points_on_a_line.h"


template<class T1, class T2>
size_t pairhash::operator()(const pair<T1, T2> &x) const {
    hash<T1> h1;
    hash<T2> h2;
    return h1(x.first) ^ h2(x.second);
}

template<class T1, class T2>
bool EqualKey::operator()(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) const {
    return lhs.first == rhs.first
           && lhs.second == rhs.second;
}

int Solution::maxPoints(vector<Point> &points) {
    int delta_x, delta_y, gcd, totalmax = 0;
    for (int i = 0; i < points.size(); ++i) {
        int duplicate = 0;
        int localmax = 0;
        unordered_map<pair<int, int>, int, pairhash, EqualKey> slopes;
        for (int j = i + 1; j < points.size(); ++j) {
            if (points[j].x == points[i].x) {
                if (points[j].y == points[i].y) {
                    //duplicate
                    duplicate++;
                    continue;
                } else {
                    //vertical
                    slopes[make_pair(1, 0)]++;
                    delta_y = 1;
                    delta_x = 0;
                }
            } else {
                delta_x = points[j].x - points[i].x;
                delta_y = points[j].y - points[i].y;
                gcd = GCD(delta_y, delta_x);
                delta_y /= gcd;
                delta_x /= gcd;
                //collect
                slopes[make_pair(delta_y, delta_x)]++;

            }
            localmax = max(localmax, slopes[make_pair(delta_y, delta_x)]);
        }
        totalmax = max(localmax + duplicate + 1, totalmax);
    }
    cout << totalmax;
    return totalmax;
}

int Solution::GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
