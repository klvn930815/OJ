//
// Created by Qiezz on 18-2-6.
//
#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold > 0 && rows > 0 && cols > 0){
            vector<bool> visited(rows * cols, false);
            return movingCountCore(threshold, rows, cols, 0, 0, visited);
        }
        return 0;
    }
    int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<bool>& visited){
        if(row >= 0 && row < rows && col >= 0 && col < cols && !visited[row * cols + col]){
            visited[row * cols + col] = true;
            int sum = 0, cur_row = row, cur_col = col;
            while(cur_row % 10){
                sum += cur_row % 10;
                cur_row = cur_row / 10;
            }
            while(cur_col % 10){
                sum += cur_col % 10;
                cur_col = cur_col / 10;
            }
            if(sum <= threshold){
                return 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                       + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                       + movingCountCore(threshold, rows, cols, row, col + 1, visited)
                       + movingCountCore(threshold, rows, cols, row, col - 1, visited);
            }
        }
        return 0;
    }
};