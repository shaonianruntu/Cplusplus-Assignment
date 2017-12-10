/*
 * 设计一个程序，定义一个汽车类Vehicle, 它具有一个需要
 * 传递参数的构造函数，类中的数据包括：车轮个数wheel 和车重weight ，
 * 两者作为保护成员；小车类Car 是它的私有派生类，其中包括承载人数
 * passengers; 卡车类Truck 是Vehicle 的私有派生类，其中包括承载人数
 * passengers 和载重量payload 。每个类都有相关数据的输出方法。
 */

#include <iostream>
using namespace std;

class Vehicle {
private:
	int wheels;          //车轮数
	int weight;          //车重
public:
	Vehicle(int wh, int we)
		:wheels(wh), weight(we) {}
	int get_wheels() { return wheels; }
	int get_weight() { return weight; }
	void print()
	{
		cout << "汽车   " << endl;
		cout << "*******************" << endl;
		cout << "轮子数:" << get_wheels() << endl;
		cout << "车重(t):" << get_weight() << endl;
		cout << "*******************" << endl;
		cout << "*******************\n" << endl;
	}
};

class car : public Vehicle {
private:
	int passengers;
public:
	car(int wh, int we, int pa)
		:Vehicle(wh, we), passengers(pa) {}
	int get_passengers() { return passengers; }
	void print()
	{
		cout << "轿车   " << endl;
		cout << "*******************" << endl;
		cout << "轮子数:" << get_wheels() << endl;
		cout << "车重(t):" << get_weight() << endl;
		cout << "载客数:" << get_passengers() << endl;
		cout << "*******************" << endl;
		cout << "*******************\n" << endl;
	}
};

class truck : public Vehicle {
private:
	int passengers, payload;
public:
	truck(int wh, int we, int pa, int py)
		:Vehicle(wh, we), passengers(pa), payload(py) {}
	int get_payload() { return payload; }
	int get_passengers() { return passengers; }
	void print()
	{
		cout << "卡车   " << endl;
		cout << "*******************" << endl;
		cout << "轮子数:" << get_wheels() << endl;
		cout << "车重(t):" << get_weight() << endl;
		cout << "载客数:" << get_passengers() << endl;
		cout << "载重(t):" << get_payload() << endl;
		cout << "*******************" << endl;
		cout << "*******************\n" << endl;
	}
};

int main() {
	Vehicle v1(4, 4);
	car c1(4, 2, 2);
	truck t1(8, 10, 2, 30);
	v1.print();
	c1.print();
	t1.print();
	system("PAUSE");
	return 0;
}
