#include "word_ladder/word_ladder.h"
//#include "Longest_Substring_Without_Repeating_Characters/Longest_Substring_Without_Repeating_Characters.cpp"
using namespace std;

int main(){
    string beginWord = "qa";
    string endWord = "sq";
    string words[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm",
                      "ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe",
                      "ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb",
                      "if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi",
                      "qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi",
                      "am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    vector<string> wordList(words, words + sizeof(words) / sizeof(words[0]));
    Solution s = Solution();
    vector<vector<string> > results = s.findLadders(beginWord, endWord, wordList);
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;


}