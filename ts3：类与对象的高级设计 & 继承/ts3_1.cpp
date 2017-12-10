/*
 * 定义和实现栈类 Stack。
 * 该类包括栈的常用操作如下所列：
 * 入栈操作               Push()
 * 出栈操作               Pop()
 * 清空栈操作             Clear()
 * 获取栈顶元素操作        Peek()
 * 判断栈空操作            IsEmpty()
 * 判断栈满操作            IsFull()
 * 成员函数的参数根据需要自定义，同时写一个程序，定义一个栈类的对象
 * 数组来验证该类的操作。提示：假定栈用来存放100个整数，栈的成员变
 * 量可以用数组来表示。
 */

#include<stack>
#include<iostream>
using namespace std;
#define STACK_H_

class Stack {
private:
	int top;
	enum { MAXLEN = 10 };
	int array[MAXLEN];
public:
	Stack() { top = 0; }
	bool IsEmpty();	//判断栈是否为空 
	bool IsFull();	//判断栈是否为满 
	bool pop(int &e);	//出栈 
	bool push(int e);	//入栈
	bool Clear();	//清空栈 
	bool Peek(int &e);	//获取栈顶元素 
};

bool Stack::IsEmpty() {
	if (top == 0)
		return 1;
	else
		return 0;
};

bool Stack::IsFull() {
	if (top == MAXLEN)
		return 1;
	else
		return 0;
};

bool Stack::pop(int &e) {
	if (IsEmpty())
		return 0;
	--top;
	e = array[top];
	return 1;
};

bool Stack::push(int e) {
	if (IsFull())
		return 0;
	array[top] = e;
	top++;
	return 1;
};

bool Stack::Clear() {
	while (!IsEmpty())
		Stack::top;
	return 1;
};

bool Stack::Peek(int &e) {
	if (IsEmpty()) 
		return 0;
	e = array[top];
	return 1;
}

int main() {
	Stack st;
	int b;
	st.push(b = 0);
	cout << "入栈：b = " << b;
	st.push(b = 1);
	cout << "  " << b;
	st.push(b = 2);
	cout << "  " << b;
	st.push(b = 5);
	cout << "  " << b << endl;
	int a = 0;
	st.pop(a);
	cout << "出栈：a = " << a;
	st.pop(a);
	cout << "  " << a;
	st.pop(a);
	cout << "  " << a;
	st.pop(a);
	cout << "  " << a << endl;
	system("PAUSE");
	return 0;
}
