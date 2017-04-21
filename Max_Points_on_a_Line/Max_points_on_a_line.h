
#ifndef OJ_MAX_POINTS_ON_A_LINE_H
#define OJ_MAX_POINTS_ON_A_LINE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};
/**
 * define a hash function for pair
 */
struct pairhash
{
    template<class T1, class T2>
    size_t operator() (const pair<T1, T2> &x) const;
};
/**
 * overlap the equal operator for pair
 */
struct EqualKey
{
    template<class T1, class T2>
    bool operator () (const pair<T1, T2> &lhs,const pair<T1, T2> &rhs) const;
};
class Solution {
public:
    int maxPoints(vector<Point>& points);
    int GCD(int a, int b);
};
#endif //OJ_MAX_POINTS_ON_A_LINE_H
