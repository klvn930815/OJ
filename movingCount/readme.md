地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

这道题与在矩阵里寻找路径类似，也可以用递归的方法匹配完一个格子之后，在周围四个格子继续匹配，但要注意同样需要设置一个visited数组记录当前格子是否已经访问过，否则代码会陷入死循环。