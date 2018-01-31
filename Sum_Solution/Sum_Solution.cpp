//
// Created by Qiezz on 18-1-31.
//

class add{
public:
    add(){
        N++;
        sum += N;
    }
    static int getSum(){
        return sum;
    }
    static void init(){
        N = 0;
        sum = 0;
    }
private:
    static int N;
    static int sum;
};


//-------------------------------------------
class A;
A* array[2];

class A{
public:
    virtual int sum(int n){
        return 0;
    }

};
class B: public A{
    virtual int sum(int n){
        return array[n!=0]->sum(n-1) + n;
    }
};

class Solution {
public:
    int Sum_Solution1(int n) {
        add::init();
        add *a = new add[n];
        return add::getSum();
    }
// --------------------------------
    int Sum_Solution2(int n) {
        A a;
        B b;
        array[0] = &a;
        array[1] = &b;
        return array[1]->sum(n);
    }
};

