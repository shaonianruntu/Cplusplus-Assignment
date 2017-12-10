/*
 * 编写一个简单的C++程序，求满足条件abc=a!+b!+c!的所有三位数，其中abc是一个
 * 三位数。打印出a,b,c的所有可能的结果.
 */ 

#include "iostream"
using namespace std;

int fac(int x);

int main(void) {
	int a, b, c;
	for (int abc = 100; abc < 1000; abc++) {
		a = abc / 100;
		b = (abc % 100) / 10;
		c = abc % 10;
		if (fac(a) + fac(b) + fac(c) == abc) {
			cout << abc << endl;
		}
	}
	system("PAUSE");
	return 0;
}

int fac(int x) {
	int y = 1;
	for (int i = x; i >= 1; i--) {
		y *= i;
	}
	return y;
}
