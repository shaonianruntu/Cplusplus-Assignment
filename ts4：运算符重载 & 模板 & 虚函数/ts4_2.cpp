/* 
 * 试使用函数模板实现求一个数组各元素的和，要求编写测试程序。
 * 函数模板声明如下：
 * template <class Type>
 * Type Sum(Type a[], int n);   	// 求数组a各元素的和
 */

#include <iostream>
using namespace std;
template <class Type>

Type Sum(Type a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + a[i];
	return sum;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5};
	cout << Sum(a, 5) << endl;

	system("PAUSE");
	return 0;
}
