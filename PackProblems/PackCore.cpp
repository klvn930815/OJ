//
// Created by Qiezz on 18-3-6.
//

#include <vector>

using namespace std;

/**
 * 0-1背包，倒序
 * @param cost 占用开销
 * @param weight 价值
 * @param f 开销容量向量
 */
void ZeroOnePack(int cost, int weight, vector<int> &f){
    for (int j = f.size(); j > 0; --j) {
        f[j] = max(f[j], f[j - cost] + weight);
    }
}

/**
 * 完全背包，顺序
 * @param cost 占用开销
 * @param weight 价值
 * @param f 开销容量向量
 */
void CompletePack(int cost, int weight, vector<int> &f) {
    for (int j = 0; j < f.size(); ++j) {
        f[j] = max(f[j], f[j - cost] + weight);
    }
}

/**
 * 多重背包，如果数量×开销超过总容量，那么相当于完全背包，
 * 如果不超过，按二进制拆分成若干个只能选一次的背包，用0-1背包解决
 * @param cost 占用开销
 * @param weight 价值
 * @param num 物品数量
 * @param f 开销容量向量
 */
void MultiplePack(int cost, int weight, int num, vector<int> &f){
    if (num * weight >= f.size()){
        CompletePack(cost, weight, f);
    }
    int k = 1;
    while(k < num){
        if (k & num){
            ZeroOnePack(k * cost, k * weight, f);
        }
        k *= 2;
    }
}

