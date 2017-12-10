/* 
 * 定义整数集合类IntSet，该类包括如下成员函数：
 * 1. IntSet(); //类的构造函数，根据需要可以定义多个构造函数
 * 2. Empty(); //清空该整数集合
 * 3. IsEmpty(); //判断整数集合是否为空
 * 4. IsMemberOf(); //判断某个整数是否在该整数集合内
 * 5. Add(); //增加一个整数到整数集合中
 * 6. Sub(); //从整数集合中删除一个整数元素
 * 7. IsEqual(); //判断两个集合是否等价
 * 8. Intersection(); //求两个整数集合的交集
 * 9. Union(); //求两个整数集合的并集
 * 10. Print(); //依次输出该集合的每个元素
 * 该类还包括如下数据成员：
 * 1. element[100]; //保存整数集合数据
 * 2. count; //记录数组中元素的个数
 * 注意：整数集合中不允许有相同元素存在。另外，上述诸函数的参数及其返回类型，
 * 根据需要自定义。
 */


#include "iostream"
using namespace std;

class IntSet {
private:
	int element[100];
	int EndPosition; 
public:
	IntSet() {
		for (int i = 0; i < 100; i++) {
			element[i] = 0;
		}
		EndPosition = -1;
	}
	IntSet(int a[], int size) {
		if (size > 99)
			EndPosition = 99;
		else
			EndPosition = size - 1;
		for (int i = 0; i <= EndPosition; i++) {
			element[i] = a[i];
		}
		for (int i = EndPosition + 1; i < 100; i++) {
			element[i] = 0;
		}
	}
	//清空该整数集合
	void Empty() {
		for (int i = 0; i <= EndPosition; i++) {
			element[i] = 0;
		}
		EndPosition = -1;
	}
	//判断整数集合是否为空
	bool IsEmpty() {
		if (EndPosition == -1)
			return true;
		else
			return false;
	}
	//判断某个整数是否在该整数集合内
	bool IsMemberOf(int x) {
		for (int i = 0; i <= EndPosition; i++) {
			if (element[i] == x)
				return true;
		}
		return false;
	}
	//增加一个整数到整数集合中
	bool Add(int x) {
		if (IsMemberOf(x))
			return false;
		else {
			EndPosition++;
			element[EndPosition] = x;
			return true;
		}
	}
	//从整数集合中删除一个整数元素
	bool Sub(int x) {
		int flag = -1;
		if (!IsMemberOf(x))
			return false;
		else {
			for (int i = 0; i <= EndPosition; i++) {
				if (element[i] = x) {
					flag = i;
					break;
				}
			}
			for (int i = flag; i < EndPosition; i++) {
				element[i] = element[i + 1];
			}
			EndPosition--;
			return true;
		}
	}
	//判断两个集合是否相等
	bool IsEqual(IntSet &a) {
		if (a.EndPosition != EndPosition)
			return false;
		for (int i = 0; i <= EndPosition; i++) {
			if (element[i] != a.element[i])
				return false;
		}
		return true;
	}
	//求两个整数集合的交集
	IntSet Intersection(IntSet &a) {
		int intersectionSet[100];
		int size = 0;
		for (int i = 0; i <= EndPosition; i++) {
			for (int j = 0; j <= a.EndPosition; j++) {
				if (element[i] == a.element[j]) {
					intersectionSet[size] = element[i];
					size++;
					break;
				}
			}
		}
		return IntSet(intersectionSet, size);
	}
	//求两个整数集合的并集
	IntSet Merge(IntSet &a) {
		int intersectionSet[100];
		int size = 0;
		for (int i = 0; i <= EndPosition; i++)
			intersectionSet[i] = element[i];
		size = EndPosition + 1;
		for (int i = 0; i <= a.EndPosition; i++) {
			if (IsMemberOf(a.element[i]))
				continue;
			else {
				if (size == 100)
					break;
				intersectionSet[size] = a.element[i];
				size++;
			}
		}
		return IntSet(intersectionSet, size);
	}
	//依次打印该整数集合
	void Print() {
		for (int i = 0; i <= EndPosition; i++) {
			cout << element[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[5] = { 0, 3,10,12,15 };
	IntSet set_1(a, 10), set_2(b, 5), set_3;
	cout << "set_1 的集合是：";
	set_1.Print();
	cout << "set_2 的集合是：";
	set_2.Print();



	cout << "set_1 集合是否为空：";
	set_1.IsEmpty();

	cout << "整数 4 是否在 set_1 集合中：";
	set_1.IsMemberOf(4);

	cout << "增加整数 0 到 set_1 集合中后 set_1 集合：";
	set_1.Add(0);
	set_1.Print();

	cout << "从 set_1 集合中删除元素 10 后输出 set_1 集合：";
	set_1.Sub(10);
	set_1.Print();

	cout << "判断 set_1 和 set_2 是否相等：";
	set_1.IsEqual(set_2);

	cout << "set_1 和 set_2 的交集是：";
	set_3 = set_1.Intersection(set_2);
	set_3.Print();
	cout << "";

	cout << "set_1 和 set_2 的并集是：";
	set_3 = set_1.Merge(set_2);
	set_3.Print();
	cout << "";

	cout << "清空 set_2 集合后 set_2 集合的输出：";
	set_2.Empty();
	set_2.Print();

	system("PAUSE");
	return 0;

}
