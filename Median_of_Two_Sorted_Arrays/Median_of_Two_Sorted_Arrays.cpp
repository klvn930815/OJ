//
// Created by Qiezz on 17-8-17.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMed(vector<int>& nums1, vector<int>& nums2){
        if ((nums1.size() + nums2.size()) & 1){
            return findkth(nums1, nums2, 1, 1, (nums1.size() + nums2.size())/2 + 1);
        }else{
            return (findkth(nums1, nums2, 1, 1, (nums1.size() + nums2.size())/2)
                   + findkth(nums1, nums2, 1, 1, (nums1.size() + nums2.size())/2 + 1)) / 2;
        }


    }
    double findkth(vector<int>& nums1, vector<int>& nums2, long a_start, long c_start, long index){
        long a_end, c_end;
        if(nums1.size() < a_start && nums2.size() >= c_start){
            return nums2[c_start + index - 2];
        }else if(nums2.size() < c_start && nums1.size() >= a_start){
            return nums1[a_start + index - 2];
        }else if (nums2.size() < c_start && nums1.size() < a_start){
            return 0;
        }else if (index == 1){
            return min(nums1[a_start - 1], nums2[c_start - 1]);
        }else{
            if (min(nums1.size() - a_start + 1, nums2.size() - c_start + 1) < index / 2){
                if (nums1.size() - a_start < nums2.size() - c_start){
                    a_end = nums1.size();
                    c_end = c_start + index - nums1.size() - 1;
                }else{
                    c_end = nums2.size();
                    a_end = a_start + index - nums2.size() - 1;
                }
            }else{
                a_end = a_start + index / 2 - 1;
                c_end = c_start + index / 2 - 1;
            }
            if (nums1[a_end - 1] < nums2[c_end - 1]){
                return findkth(nums1, nums2, a_end + 1, c_start, index - a_end + a_start - 1);
            }else if(nums1[a_end - 1] > nums2[c_end - 1]){
                return findkth(nums1, nums2, a_start, c_end + 1, index - c_end + c_start - 1);
            }else{
                if (index & 1){
                    return findkth(nums1, nums2, a_end + 1, c_end + 1, index - index / 2 * 2);
                }else{
                    return nums1[a_end - 1];
                }
            }
        }
    }
};
