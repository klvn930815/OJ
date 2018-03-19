//
// Created by Qiezz on 18-3-19.
//

/* 题目：
 * 小易准备去魔法王国采购魔法神器,购买魔法神器需要使用魔法币,
 * 但是小易现在一枚魔法币都没有,但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法币产生更多的魔法币。
 * 魔法机器1:如果投入x个魔法币,魔法机器会将其变为2x+1个魔法币
 * 魔法机器2:如果投入x个魔法币,魔法机器会将其变为2x+2个魔法币
 * 小易采购魔法神器总共需要n个魔法币,所以小易只能通过两台魔法机器产生恰好n个魔法币,
 * 小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。
 *
 * 思路：
 * 用递归的方法做，对于n个魔法币，如果是奇数，那么最后使用的是魔法机器1，否则是机器2,
 * 然后回到上一个状态，以相同的方法继续逆推，直到0个币。
 */


#include<iostream>
using namespace std;


bool MagicCoins(int n, string& seq){
    if(n){
        if((n & 1) == 0 && MagicCoins((n - 2) / 2, seq)){
            seq.push_back('2');
            return true;
        }
        if(n & 1  && MagicCoins((n - 1) / 2, seq)){
            seq.push_back('1');
            return true;
        }
        return false;
    }
    return true;
}