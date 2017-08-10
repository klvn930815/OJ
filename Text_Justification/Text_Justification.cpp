//
// Created by Qiezz on 17-8-4.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> output;
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        insert_string(words, maxWidth);
        return this->output;

    }
    void insert_string(vector<string>& words, int maxWidth){
        // create a empty string
        string result = " ";
        for (int i = 0; i < maxWidth - 1; ++i) {
            result += " ";
        }
        if (words.size() == 0 || words[0].size() == 0){
            if (maxWidth){
                this->output.push_back(result);
            }else{
                this->output.push_back("");
            }
        }
        else if (words.size() == 1){
            result.replace(0, words[0].size(), words[0]);
            this->output.push_back(result);
        }
        else{
            // get the number of the words
            int current_width = words[0].size();
            int current_number = 1;
            for (int i = 1; i < words.size(); ++i) {
                if (current_width + 1 + words[i].size() <= maxWidth){
                    current_width += 1 + words[i].size();
                    current_number ++;
                }else{ break;}
            }
            if (current_number == words.size() || current_number == 1){
                int head = 0;
                //insert from the head
                for (int i = 0; i < current_number; ++i) {
                    result.replace(head, words[i].size(), words[i]);
                    head += (words[i].size() + 1);
                }
                this->output.push_back(result);
            }else{
                // insert from the end
                int extra_space = maxWidth - current_width;
                int even_space = extra_space / (current_number - 1);
                // the last one
                int tail = maxWidth - words[current_number - 1].size() - 1;
                result.replace(maxWidth - words[current_number - 1].size(), words[current_number - 1].size(),
                               words[current_number - 1]);
                cout<<result<<endl;
                for (int j = current_number - 2; j > 0; --j) {
                    result.replace(tail - even_space - words[j].size(), words[j].size(), words[j]);
                    tail -= (even_space + words[j].size() + 1);
                    if (j > 1){
                        extra_space -= even_space;
                        even_space = extra_space / j;
                    }
                    cout<<result<<endl;
                }
                // the first one
                result.replace(0, words[0].size(), words[0]);
                cout<<result<<endl;
                this->output.push_back(result);
            }
            for (int k = 0; k < current_number; ++k) {
                words.erase(words.begin());
            }
            if (!words.empty()) {
                insert_string(words, maxWidth);
            }
        }
    }
};