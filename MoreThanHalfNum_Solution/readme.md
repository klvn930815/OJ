数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

这道题相当于找这个数组的中位数, 也就是第k/2大的数. 具体做法是利用partition算法，选择枢纽元，将数列分成两部分，前半部分都小于枢纽元，后半部分都大于枢纽元。如果这个枢纽元正好在第k/2个位置，那么这个枢纽元就是要找的数; 如果下标大于k/2,说明要找的数在前半部分，对前半部分继续使用partition算法，否则对后半部分使用partition算法。这个做法可以扩展为找第任意大的数。缺点是需要修改原来的数组。





