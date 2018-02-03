//
// Created by Qiezz on 18-2-1.
//

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length == 0) {
            return false;
        }
        int m = -1, temp;
        for (int i = 0; i < length; ++i) {
            while(numbers[i] != i){
                m = numbers[i];
                if(numbers[i] != numbers[m]){
                    temp = numbers[i];
                    numbers[i] = numbers[m];
                    numbers[m] = temp;
                }else{
                    *duplication = numbers[i];
                    return true;
                }
            }

        }
        return false;
    }
};