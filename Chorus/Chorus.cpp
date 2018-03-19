//
// Created by Qiezz on 18-3-19.
//

/* 题目：
 * 小Q和牛博士合唱一首歌曲,这首歌曲由n个音调组成,每个音调由一个正整数表示。
 * 对于每个音调要么由小Q演唱要么由牛博士演唱,对于一系列音调演唱的难度等于所有相邻音调变化幅度之和,
 * 例如一个音调序列是8, 8, 13, 12, 那么它的难度等于|8 - 8| + |13 - 8| + |12 - 13| = 6(其中||表示绝对值)。
 * 现在要对把这n个音调分配给小Q或牛博士,让他们演唱的难度之和最小,请你算算最小的难度和是多少。
 * 如样例所示: 小Q选择演唱{5, 6}难度为1, 牛博士选择演唱{1, 2, 1}难度为2,难度之和为3,这一个是最小难度和的方案了。
 *
 * 思路：
 * 用动态规划的思路解决。
 * 建立二维矩阵turns，turns[i][j]表示第一个人和第二个人最近唱的分别是第i和j个音调(1<=i,j<=n),0表示还没唱。
 * 很容易看出turns是对称矩阵，所以可以只计算其中一半的值，那么就规定i > j。
 * 状态转移时有2种情况：
 * 1. i-1 > j, 那就是说第(i-1)个音调也是第一个人唱的，turns[i][j] 在 turns[i - 1][j] 基础上叠加
 * 2. i-1 == j, 就是说第(i-1)个音调是第二个人唱的，两人交替唱了，turns[i][i-1] = min(turns[k][i-1] + (level[i] - level[k]))，
 * k的取值范围是0到j-2。注意当k为0时，第一个人还没有唱，不需要计算前后两个音调差。
 * 由于前面设定i>j，而且turns是对称矩阵，因此第二种情况可以变形为turns[i][i-1] = min(turns[i-1][k] + (level[i] - level[k]))
 *
 */

#include<iostream>
#include<vector>
#include <limits>
using namespace std;


int chorus(vector<int>& level){
    // 第0个音表示没发音
    level.insert(level.begin(), 0);
    vector<vector<int> > turns(level.size(), vector<int>(level.size(), numeric_limits<int>::max()));
    // 初始化一些状态
    turns[0][0] = turns[1][0] = 0;
    for (int i = 2; i < level.size(); ++i) {
        for (int j = 0; j < i - 1; ++j) {
            turns[i][j] = turns[i - 1][j] + abs(level[i] - level[i - 1]);
            // 如果是0, 即还没唱，那么不管哪个音，音差都是0。
            if(j == 0){
                turns[i][i - 1] = min(turns[i][i - 1], turns[i - 1][j]);
            }else{
                turns[i][i - 1] = min(turns[i][i - 1], turns[i - 1][j] + abs(level[i] - level[j]));
            }
        }
    }
    int min = numeric_limits<int>::max();
    for (int k = 0; k < level.size() - 1; ++k) {
        min = turns[level.size() - 1][k] < min ? turns[level.size() - 1][k] : min;
    }
    return min;
}