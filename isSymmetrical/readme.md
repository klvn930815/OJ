请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

题目说明里给了一种思路，就是创建另一个镜像树，然后递归地进行比较，包括当前节点比较、左子树和左子树比较和右子树和右子树比较，而创建方法就是从根节点开始递归，交换每个节点的左右子树。这样的话需要辅助空间O(N), 时间开销O(N)。但可以不用另外创建一棵树。假设在比较的时候有左节点和右节点，比较了左右节点本身之后，取左节点的右子树和右节点的左子树比较，然后取左节点的左子树和右节点的右子树比较。左右节点分别从根节点的左右孩子出发，然后进行递归。