//
// Created by Qiezz on 18-2-5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix != NULL &&  rows > 0 && cols > 0 && str != NULL) {
            int cur_len = 0;
            vector<bool>visited(rows * cols, false);
            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    if(hasPathCore(matrix, rows, cols, row, col, cur_len, str, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasPathCore(char* matrix, int rows, int cols, int row, int col, int& cur_len, char* str, vector<bool> &visited){
        if(*(str + cur_len) == '\0'){
            return true;
        }
        bool haspath = false;
        if(row < rows && row >= 0 && col < cols && col >= 0 && matrix[row * cols + col] == str[cur_len]
           && visited[row * cols + col] == false){
            cur_len ++;
            visited[row * cols + col] = true;
            haspath = hasPathCore(matrix, rows, cols, row - 1, col, cur_len, str, visited)
                    || hasPathCore(matrix, rows, cols, row + 1, col, cur_len, str, visited)
                    || hasPathCore(matrix, rows, cols, row, col - 1, cur_len, str, visited)
                    || hasPathCore(matrix, rows, cols, row, col + 1, cur_len, str, visited);
            if(!haspath){
                cur_len --;
                visited[row * cols + col] = false;
            }
        }
        return haspath;
    }
};