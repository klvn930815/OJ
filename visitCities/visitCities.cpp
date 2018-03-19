//
// Created by Qiezz on 18-3-19.
//
#include<iostream>
#include<vector>
using namespace std;


/* 题目：
 * 魔法王国一共有n个城市,编号为0~n-1号,n个城市之间的道路连接起来恰好构成一棵树。
 * 小易现在在0号城市,每次行动小易会从当前所在的城市走到与其相邻的一个城市,小易最多能行动L次。
 * 如果小易到达过某个城市就视为小易游历过这个城市了,小易现在要制定好的旅游计划使他能游历最多的城市,
 * 请你帮他计算一下他最多能游历过多少个城市(注意0号城市已经游历了,游历过的城市不重复计算)。
 *
 * 思路：
 * 首先只要找到最长的一条路径就好，对于树来说就是到达最深叶子的路径，
 * 只要保证最长路径只走一次，多余的步数再去访问其他节点，就能计算能够访问的最多节点数。
 * 每2步能遍历到分支上的1个点。
 */

int visitCities(int num, int length, vector<int>& con){
    if(con.size()){
        int max = -1;
        con[0] = 0;
        for (int i = 0; i < con.size(); ++i) {
            con[i] = con[con[i]] + 1;
            max = max < con[i] ? con[i] : max;
        }
        if(max - 1 >= length){
            return length + 1;
        }
        return min((length - max + 1) / 2 + max, num);
    }
    return 0;
}
