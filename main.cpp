//#include "word_ladder/word_ladder.h"
//#include "Longest_Substring_Without_Repeating_Characters/Longest_Substring_Without_Repeating_Characters.cpp"
//#include "Max_Points_on_a_Line/Max_points_on_a_line.h"
//#include "LRU_cache/LRU.h"
//#include "palindrome/palindrome.cpp"
#include "Text_Justification/Text_Justification.cpp"


int main(){
    vector<string> words = {"so","fine","That","all","the","world","will","be","in","love","with","night","And","pay","no","worship","to","the","garish","sun."};

    int length = 25;
    Solution s;
    vector<string> out = s.fullJustify(words, length);
    for (int i = 0; i < out.size(); ++i) {
        cout<<out[i]<<endl;
    }

}