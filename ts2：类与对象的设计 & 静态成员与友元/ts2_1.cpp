/* 
 * 编写一个程序，已有若干学生的数据，包括学号、姓名、成绩，要求输出
 * 这些学生的数据并计算出学生人数和平均成绩（将学生人数和总成绩用静
 * 态数据成员表示）。
 */

#include "iostream"
#include "string"
using namespace std;

class Student{
private:
    int stuid;
    string name;
    int score;
    static int number;
    static int sum;
    static int average;
public:
    Student(int id, string name, int sco);
    void show(){
        cout << "学号:" << number << " 姓名:" << name << "成绩：" << score << endl;
    }
    static void print(){
        cout << "学生数量：" << number << endl;
        cout << "平均成绩:" << average <<endl;
    }
};

Student::Student(int id, string name, int sco){
    stuid = id;
    name = name;
    score = sco;
    number += 1;
    sum += score;
    average = int(sum / number);
}

// void Student::show(){
//     cout << "学号:" << number << " 姓名:" << name << "成绩：" << score << endl;
// }

// static void Student::print(){
//     cout << "学生数量：" << number << endl;
//     cout << "平均成绩:" << average <<endl;
// }

int Student::number = 0;
int Student::sum = 0;
int Student::average = 0;

int main(){
    Student stu[4] = {
        Student(3, "张三", 80),
        Student(4, "李四", 90),
        Student(5, "王五", 100),
        Student(6, "赵六", 70)
    };

    for(int i = 0; i < 4; i++){
        stu[i].show();
    }

    Student::print();
    return 0;
}
