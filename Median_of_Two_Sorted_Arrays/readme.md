
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

```Example 1:
   nums1 = [1, 3]
   nums2 = [2]
   The median is 2.0
```

Example 2:
```
    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5
```

一开始想的是要去递归地把两个数列对半分（因为log..），nums1变成a和b两段，nums2变成c和d两段，取a和c出来，比较a和c的最大值，
假设a.size() + c.size() > (m+n)/2， 会有三种结果:

(1)a的大于c的,那么median不可能出现在d里，直接丢掉d，新array是nums1和c;

(2)小于，那么median不可能出现在b里，直接丢掉b，新array是a和nums2;

(3)等于，那么median不可能出现在b和d，b和d都丢弃，新array是a和b;

得到新array后继续递归。

但是发现分的情况太多，然后看到大神的解答，发现在寻找第k小数时，改成两个数列直接取前k/2个数，并改为抛弃前面一段的更好，
可以不用针对a.size() + c.size()与k的相对大小分太多情况，而且终止递归更快。假设当前是寻找第k小的数，具体如下：
(1)a的大于c的,那么median不可能出现在c里, 丢弃c，新array是nums1和d, 寻找第(k-c.size())小的数;

(2)小于，那么median不可能出现在a里，直接丢掉a，新array是b和nums2, 寻找第(k-b.size())小的数;

(3)等于，那么这两个最大值就是要找的当前两个数列的第k小数，递归终止。

这个k需要注意一下，如果k为偶数，k/2 * 2=k，但是k为奇数时，即使得到等于的结果，其实也只是找到第k-1小的数，
还需要进入下一个循环。然后需要考虑边界条件，如其中一个数组为空等。