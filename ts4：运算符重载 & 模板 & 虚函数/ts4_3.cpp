/*
 * 设计一个基类Shape，Shape中包含成员函数Show()，将Show()声明为纯虚函数。
 * Shape类公有派生矩形类Rectangle和圆类Circle，分别定义Show()实现其主要
 * 几何元素的显示。使用抽象类Shape类型的指针，当它指向某个派生类的对象时，
 * 就可以通过它访问该对象的虚成员函数Show()，要求编写测试程序。
 */ 

#include<iostream>
using namespace std;
const double PI = 3.1415926;

class Shape
{
public:
	virtual	~Shape() {}
	virtual void Show() const = 0;
};

class Rectangle : public Shape
{
private:
	double height;
	double width;
public:
	Rectangle(double h, double w) : height(h), width(w) {}
	void Show() const
	{
		cout << "矩形的高：" << height << endl;
		cout << "矩形的宽：" << width << endl;
		cout << "矩形的周长：" << 2 * (height + width) << endl;
		cout << "矩形的面积：" << height*width << endl << endl;
	}
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double r) :radius(r) {}
	void Show()const
	{
		cout << "圆的半径：" << radius << endl;
		cout << "圆的周长：" << 2 * PI*radius << endl;
		cout << "圆的面积：" << PI*radius*radius << endl << endl;

	}
};

int main()
{
	Shape *p;
	p = new Circle(3);
	p->Show();
	delete p;
	p = new Rectangle(3, 4);
	p->Show();
	delete  p;

	system("PAUSE");
	return 0;
}
