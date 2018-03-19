//
// Created by Qiezz on 18-3-10.
//

/*
 * 题目：处理str1，把在str2中没出现的字符删除，并返回str1。
 *
 * 思路：
 * 先遍历一遍str2, 用vector记录每个字符是否出现过，字符直接作为下标，
 * 然后用两个指针遍历str1,两个指针一起出发，
 * 如果第一个指针指向的字符在str2存在，就把该字符复制给第二个指针的位置，然后两个指针都向后移动一位
 * 如果不存在，那么第一个指针向后移动一位，第二个指针不动。
 */

#include<iostream>
#include<vector>

using namespace std;

char* intersectStr(char *str1, char *str2){
    if(str1==nullptr || str2==nullptr)
        return str1;
    vector<bool> vInStr2(256, false);

    for(int i = 0; str2[i]!='\0'; i++)
        vInStr2[int(str2[i])] = true;

    int nCur = 0, nPos = 0;
    while(str1[nCur]!='\0'){
        if(vInStr2[int(str1[nCur])]){
            cout<<nPos<<nCur<<endl;
            str1[nPos++] = str1[nCur++];
            cout<<"yes"<<endl;
        }
        else
            nCur++;
    }
    str1[nPos] = '\0';
    return str1;
}

//int main(){
//    char str1[] = "Welcome CVTE";
//    char str2[] = "KEem";
//    char *res = intersectStr(str1, str2);
//    for(int i = 0; res[i]!='\0'; ++i)
//        cout<<res[i];
//}