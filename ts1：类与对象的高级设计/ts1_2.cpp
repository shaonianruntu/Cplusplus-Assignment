/*
 * 设计一个Date类，
 * （1）用下面的格式输出日期： 年-月-日 
 * （2） 设置日期。并编写程序，定义日期对象，设置日期，输出该对象提供的日期。
 */

#include "iostream"
using namespace std;

class Date {
private:
	int year = 0;
	int month = 0;
	int day = 0i;

public:
	void print() {
		cout << year << "-" << month << "-" << day << endl;
	}
	void setData(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
};

int main() {
	Date date;
	date.setData(2017, 10, 16);
	date.print();
	system("PAUSE");
	return 0;
}
