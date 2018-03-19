//
// Created by Qiezz on 18-3-19.
//

/*
 * 小易正在玩一款新出的射击游戏,这个射击游戏在一个二维平面进行,小易在坐标原点(0,0),
 * 平面上有n只怪物,每个怪物有所在的坐标(x[i], y[i])。小易进行一次射击会把x轴和y轴上(包含坐标原点)的怪物一次性消灭。
 * 小易是这个游戏的VIP玩家,他拥有两项特权操作:
 * 1、让平面内的所有怪物同时向任意同一方向移动任意同一距离
 * 2、让平面内的所有怪物同时对于小易(0,0)旋转任意同一角度
 * 小易要进行一次射击。小易在进行射击前,可以使用这两项特权操作任意次。
 * 小易想知道在他射击的时候最多可以同时消灭多少只怪物,请你帮帮小易。
 *
 * 移动怪物相当于移动十字，所以这道题就是寻找一个十字，经过尽量多的怪物点。
 * 做法是遍历所有怪物点...
 */
#include<iostream>
#include<vector>
using namespace std;

int shoots(int num, vector<int> x, vector<int> y){
    int max = -1, count;
    if(num <= 3){
        return num;
    }
    for (int i = 0; i < num; ++i) {
        for (int j = i + 1; j < num; ++j) {
            for (int k = 0; k < num; ++k) {
                if(k == i || k == j) continue;
                count = 0;
                for (int l = 0; l < num; ++l) {
                    if(l == k|| l == j || l == i) continue;
                    if((x[j] - x[i]) * (x[l] - x[k]) + (y[l] - y[k]) * (y[j] - y[i]) == 0 ||
                       (x[j] - x[i]) * (y[l] - y[i]) - (x[l] - x[i]) * (y[j] - y[i]) == 0){
                        count += 1;
                    }
                }
                if(max < count){
                    max = count;
                }
            }
        }
    }
    return max + 3;
}
