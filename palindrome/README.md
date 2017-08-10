 
## 564. Find the Closest Palindrome

Given an integer n, find the closest integer (not including itself), which is a palindrome.
The 'closest' is defined as absolute difference minimized between two integers.

Note:
1. The input n is a positive integer represented by string, whose length will not exceed 18.
2. If there is a tie, return the smaller one as answer.

(参考了leetcode大神们的思路)假设n的为k位数，那么基本思路在于取n的前半部分数字p,即前(k+1)/2位，取p，p+1，p-1然后重复得到后半部分。其次是要注意边界，即进位和退位的情况。那么候选范围里面的最小回文数就是10^(k-1)-1,最大回文数就是10^k+1.

一开始没有考虑到进位退位的情况，