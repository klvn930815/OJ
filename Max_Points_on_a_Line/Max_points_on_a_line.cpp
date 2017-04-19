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

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int delta_x, delta_y, gcd, totalmax = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 0;
            int localmax = 0;
            map<pair<int,int>,int> slopes;
            for (int j = i + 1; j < points.size(); ++j) {
                if(points[j].x == points[i].x){
                    if(points[j].y == points[i].y){
                        //duplicate
                        duplicate ++;
                        continue;
                    }else{
                        //vertical
                        slopes[make_pair(1,0)] ++;
                        delta_y = 1;
                        delta_x = 0;
                    }
                }else{
                    delta_x = points[j].x - points[i].x;
                    delta_y = points[j].y - points[i].y;
                    gcd = GCD(delta_y,delta_x);
                    delta_y /= gcd;
                    delta_x /= gcd;
                    //collect
                    slopes[make_pair(delta_y,delta_x)] ++;

                }
                localmax = max(localmax,slopes[make_pair(delta_y,delta_x)]);
            }
            totalmax = max(localmax + duplicate + 1,totalmax);
        }
        cout<<totalmax;
        return totalmax;
    }
    int GCD(int a, int b) {
        if(b == 0)
            return a;
        else
            return GCD(b, a%b);
    }
};