#include "word_ladder.h"

using namespace std;

vector<vector<int> > Solution::dijkstra(int start, int dest, vector<vector<int> > &adj, vector<int> &distance) {
    unsigned long num = adj.size();
    vector<bool> visited(num, false);
    visited[start] = true;

    vector<vector<int> > prevPoints;

    //init path
    for (int i = 0; i < num; ++i) {
        if (distance[i] < 999) {
            prevPoints.push_back(vector<int>(1, start));
        } else {
            prevPoints.push_back(vector<int>(1, -1));
        }
    }
    //if dest has been found
    if (prevPoints[dest][0] == start) {
        return prevPoints;
    }

    for (int i = 1; i < num; ++i) {
        // find the closest point
        int closest = 999;
        int toVisit = -1;
        for (int j = 0; j < num; ++j) {
            if (!visited[j] && distance[j] < closest) {
                closest = distance[j];
                toVisit = j;
            }
        }

        if (toVisit != -1 && toVisit != dest) {
            //update adj and path
            visited[toVisit] = true;
            for (int k = 0; k < adj[toVisit].size(); k++) {
                if (adj[toVisit][k] != -1 && !visited[adj[toVisit][k]]) {
                    if (distance[adj[toVisit][k]] > distance[toVisit] + 1) {
                        //update the distance
                        distance[adj[toVisit][k]] = distance[toVisit] + 1;
                        //clear the paths,and store the new path
                        prevPoints[adj[toVisit][k]].clear();
                        prevPoints[adj[toVisit][k]].push_back(toVisit);

                    } else if (distance[adj[toVisit][k]] == distance[toVisit] + 1) {
                        //add the new path
                        prevPoints[adj[toVisit][k]].push_back(toVisit);
                    }
                }
            }
        } else {
            break;
        }
    }
    return prevPoints;
}

bool Solution::IsConnectedWord(string a, string b) {
    int size = a.size();
    int dist = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i]) {
            if (dist) {
                return false;
            } else {
                dist++;
            }
        }
    }
    return true;
}

vector<vector<string> > Solution::findLadders(string beginWord, string endWord, vector<string> &wordList) {
    //构建邻接矩阵
    int num = wordList.size();
    int pathsNum = 1;
    int start = -1;
    int end = -1;
    int index = -1;
    bool isInList = false;
    bool existPaths = false;

    vector<vector<int> > prevPoints;
    vector<vector<string> > results;

    //check if beginWord is in the wordlist
    for (int i = 0; i < num; i++) {
        if (beginWord == wordList[i]) {
            isInList = true;
            existPaths = true;
            start = i;
            break;
        } else if (IsConnectedWord(beginWord, wordList[i])) {
            existPaths = true;
        }
    }

    if (!existPaths) {
        return results;
    }
    if (!isInList) {
        start = 0;
        num += 1;
        wordList.insert(wordList.begin(), 1, beginWord);
    }

    vector<vector<int> > adj(num, vector<int>(1, -1));
    vector<int> distance(num, 999);

    for (int i = 0; i < num; i++) {
        if (wordList[i] == endWord) {
            end = i;
        }
        for (int j = i + 1; j < num; j++) {
            if (IsConnectedWord(wordList.at(i), wordList.at(j))) {
                if (wordList[j] != beginWord) {
                    adj[i].insert(adj[i].begin(), 1, j);
                } else {
                    distance[i] = 1;
                }
                if (wordList[i] != beginWord) {
                    adj[j].insert(adj[j].begin(), 1, i);
                } else {
                    distance[j] = 1;
                }
            }
        }
    }

    if (end == -1) {
        return results;
    }
    //get the previous points
    prevPoints = dijkstra(start, end, adj, distance);

    //get the paths
    if (prevPoints[end][0] != -1) {
        index = end;
        results = getPaths(start, index, wordList, prevPoints);
    }

    return results;
}

vector<vector<string> > Solution::getPaths(int start, int index, vector<string> &wordList, vector<vector<int> > &prevPoints) {
    vector<vector<string> > childPaths;
    vector<vector<string> > midPaths;
    if (index != start) {
        for (int i = 0; i < prevPoints[index].size(); ++i) {
            childPaths = getPaths(start, prevPoints[index][i], wordList, prevPoints);
            for (int j = 0; j < childPaths.size(); ++j) {
                childPaths[j].push_back(wordList[index]);
            }
            if (midPaths.empty()) {
                midPaths = childPaths;
            } else {
                midPaths.insert(midPaths.end(), childPaths.begin(), childPaths.end());
            }
        }
    } else {
        // the beginWord
        midPaths.push_back(vector<string>(1, wordList[start]));
    }
    return midPaths;
}


