//
// Created by Qiezz on 18-3-10.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
/*
 有个穷困的艺术家。他画了一幅超现实主义的作品《方块手拉手》。现在他已经把图画中手拉手的一排大小不一的方块都画出来了。现在要考虑上颜色了。可惜他手中的钱并不多了。但是他是个有追求的人，他希望这幅画中每两个相邻的方块的颜色是不一样的。你能帮他计算一下把这幅画上色后，最少需要花多少钱么。
输入 N个方块，K个颜色
接下来每列是各个方块染成不同颜色的价钱

输出 最少花的钱

 例：
 4 3
 2 3 2
 9 1 4
 7 8 1
 2 8 3

 6

就是一排方格，既要相邻两个不同，又要花费最小
思路: 动态规划问题，对于第i个格子，每种染色都选出和前(i-1)个格子的最小组合cost，放在相应格子，就这样一格格累计上去。
*/

int minCost(vector<int> costs, int N, int K){
    int min = numeric_limits<int>::max();
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            min = numeric_limits<int>::max();
            for (int k = 0; k < K; ++k) {
                if(k == j){
                    continue;
                }
                if(costs[i * K + j] + costs[(i - 1) * K + k] < min){
                    min = costs[i * K + j] + costs[(i - 1) * K + k];
                }
            }
            costs[i * K + j] = min;
        }
    }
    min = numeric_limits<int>::max();
    for (int l = 0; l < K; ++l) {
        cout<<costs[(N - 1) * K + l]<<'\t';
        if(costs[(N - 1) * K + l] < min){
            min = costs[(N - 1) * K + l];
        }
    }
    return min;
}






