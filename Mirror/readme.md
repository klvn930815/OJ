操作给定的二叉树，将其变换为源二叉树的镜像。

思路：把叶节点看成左右子树为空的普通节点，那么从节点的角度看，实际上就是将每个节点的left和right指向的节点交换一下，而且每个节点的操作是一样的，可以用递归或者循环的方式实现。

特殊情况就是空树、一个节点的树。