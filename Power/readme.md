给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

我的初步想法是:从1开始一个一个乘到exponent显然不可能的。可以简化一下,利用exponent的二进制表示,在循环里,若右起第k位非0,则待输出的值乘上一个base^(exponent^k), 而base^(exponent^k)可以由base^(exponent^(k-1))的平方求得,也就是上一次循环的数平方一下用于当前循环.

循环最多进行32次,可以通过判断2^k和利用exponent的大小让循环在最高位1终止。

特殊情况有:

1. exponent为负数,这点取绝对值,最后对结果进行取反;

2. base为0,这个可能还是按具体情况分析吧,在c++里以0为分母得到的是inf,并不会报错退出.