#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0;
        int length = s.length() > 1 ? 1 : 0;
        int max = 0;
        int dupindex = -1;
        while(head + length < s.length()){
            dupindex = s.substr(head,length).rfind(s[head + length],head + length - 1);
            if (dupindex  != string::npos)
            {   //the duplicate char is at dupindex,
                 head = head + dupindex +1;
                 length =  length - dupindex -1;
            }
            length += 1;
            max = max>length ? max : length;
        }
        return max;
    }
};


//int main(int argc, char const *argv[])
//{
//    string str="abcdcfghjklm";
//    // cout<< str.substr(3,6).rfind("c",3);
//    // cout<<str.substr(0,2)<<'\n';
//    // cout<<str;
//    // cout<<s.length();
//    // cout<<'\n'<<string::npos;
//    Solution s = Solution();
//    cout<<"length:"<<s.lengthOfLongestSubstring(str);
//    return 0;
//}