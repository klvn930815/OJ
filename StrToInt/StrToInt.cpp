//
// Created by Qiezz on 18-2-1.
//
#include <string>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int output = 0;
        int err_sign = 0;
        int sign = 1;

        if(!str.empty()){
            // 可以设一个标记变量记录是因为输入非法导致输出为0还是本身输入为0
            if(str.size() == 1 and (str[0] - '0' > 9 or str[0] - '0' < 0)){
                err_sign = 1;
                return 0;
            }
            int s_num = 0;
            for (int i = 0; i < str.size(); ++i) {
                s_num = str[i] - '0';
                if (s_num >= 0 && s_num <= 9){
                    output = output * 10 + s_num;
                }else if (i == 0 and str[i] == '-'){
                    sign = -1;
                }else if (i == 0 and str[i] == '+'){
                    continue;
                }else{
                    err_sign = 1;
                    return 0;
                }
            }
            output *= sign;
        }else{
            err_sign = 1;
        }
        return output;
    }
};