输入一棵二叉树，判断该二叉树是否是平衡二叉树。


如果从上往下遍历结点，那么计算深度的时候底层的结点会被重复遍历。为了不重复遍历，可以从下往上遍历，也就是后序遍历，先判断子树是不是平衡树，然后再判断自己是不是平衡树，顺便计算树的深度。