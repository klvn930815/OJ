//
// Created by Qiezz on 18-1-2.
//
class Solution {
public:
    void replaceSpace(char *str,int length) {
        if (str[0] == '\0') return;
        int i = 0;
        int SpaceNum = 0;
        while(str[i] != '\0'){
            if (' ' == str[i]){
               SpaceNum ++;
            }
            i++;
        }
        int NewLength = length + 2 * SpaceNum;
        str[NewLength] = '\0';
        int ind = NewLength - 1;
        for(int j = length - 1; j >= 0; j--){
            if (' ' != str[j]){
                str[ind--] = str[j];
            } else{
                str[ind--] = '0';
                str[ind--] = '2';
                str[ind--] = '%';
            }
        }
    }
};
