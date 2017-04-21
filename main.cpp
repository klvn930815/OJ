//#include "word_ladder/word_ladder.h"
//#include "Longest_Substring_Without_Repeating_Characters/Longest_Substring_Without_Repeating_Characters.cpp"
#include "Max_Points_on_a_Line/Max_points_on_a_line.h"
#include "LRU_cache/LRU.h"


int main(){

    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;


}