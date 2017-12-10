/*
 * 定义类X,Y,Z，使之满足以下几个条件：
 * 1）类X有么一个私有成员i，
 * 2）类Y的一个成员函数f是类X的友元函数，实现对X的i加1操作。
 * 3）类Z是类X的友元类，Z的一个成员函数g实现对X的i加2操作。
 * 4）函数h是类X的友元函数，实现对X的i加3操作。
 */ 

#include "iostream"
using namespace std;

class X;

class Y{
public:
    void f(X &p);
};

class Z{
public:
    void g(X &p);
};

class X{
private:
    int i;
public:
    X(int data): i(data){};
    void print(){
        cout << i << endl;
    }
    friend void Y::f(X &p);
    friend class Z;
    friend void h(X &p);
};

void Y::f(X &p){
    p.i += 1;
}

void Z::g(X &p){
    p.i += 2;
}

void h(X &p){
    p.i += 3;
}

int main(){
    X a(0);
    Y b;
    Z c;
    a.print();
    b.f(a);
    a.print();
    c.g(a);
    a.print();
    h(a);
    a.print();

    return 0;
}
