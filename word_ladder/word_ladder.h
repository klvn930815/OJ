
#ifndef TI_WORD_LADDER_H
#define TI_WORD_LADDER_H
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    /**
     *
     * @param start 起点
     * @param dest 终点
     * @param adj 邻接链表，adj[i][k]表示节点i的第k个邻接点的索引
     * @param distance 到起点的距离
     * @return prevPoints 前驱点数组，prevPoints[k]表示到达点k的最短路径中的所有前驱点
     */
    vector<vector<int> > dijkstra(int , int , vector<vector<int> >&, vector<int>& );

    /**
     *
     * @param a 字符串a
     * @param b 字符串b
     * @return a和b邻接则返回true，否则返回false
     */
    bool IsConnectedWord(string a, string b);

    /**
     *
     * @param beginWord 起点单词
     * @param endWord 终点单词
     * @param wordList 单词节点列表
     * @return results 可行的所有最短路径
     */
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string> &wordList);

    /**
     *
     * @param start 起点
     * @param index 终点
     * @param wordList 词典
     * @param prevPoints 前驱点数组
     * @return midpaths 从start到index的所有路径
     */
    vector<vector<string> > getPaths(int start,int index,vector<string>& wordList,vector<vector<int> >& prevPoints);
};

#endif //TI_WORD_LADDER_H
