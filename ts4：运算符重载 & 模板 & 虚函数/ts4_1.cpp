/*
 * 定义一个时间（Time）类(时、分、秒)，重载“<”和“>”运算符，用来实现两个
 * 时间比较先后，如果t1时间早于t2，则t1<t2返回true，否则返回false。
 * 重载“= =”运算符，如果两个时间相同，则返回true,否则返回false。
 * 重载“-”运算符，用于计算时间之差。
 */

#include "iostream"
using namespace std;


class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time();
	Time(int h, int m, int s);
	bool operator < (Time &time);
	bool operator > (Time &time);
	bool operator == (Time &time);
	Time operator - (Time &time);

	void setHour(int h) {
		hour = h;
	}
	void setMin(int m) {
		min = m;
	}
	void setSec(int s) {
		sec = s;
	}
	int getHour(void) {
		return hour;
	}
	int getMin(void) {
		return min;
	}
	int getSec(void) {
		return sec;
	}
};

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;

	if (sec >= 60) {
		sec = sec % 60;
		min++;
	}
	if (sec < 0) {
		sec += 60;
		min--;
	}
	if (min >= 60) {
		min = min % 60;
		hour++;
	}
	if (min < 0) {
		min += 60;
		hour--;
	}
	if (hour >= 24) {
		hour = hour % 24;
	}
	if (hour < 0) {
		hour = hour + 24;
	}
}

bool Time::operator < (Time &time) {
	if (hour < time.getHour()) {
		return true;
	}
	else if (hour == time.getHour())
	{
		if (min < time.getMin()) {
			return true;
		}
		else if (min == time.getMin())
		{
			if (sec < time.getSec()) {
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool Time::operator > (Time &time)
{
	if (hour > time.getHour()) {
		return true;
	}
	else if (hour == time.getHour())
	{
		if (min > time.getMin()) {
			return true;
		}
		else if (min == time.getMin())
		{
			if (sec > time.getSec()) {
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool Time::operator == (Time &time) {
	if (hour == time.getHour()) {
		if (min == time.getMin()) {
			if (sec == time.getSec()) {
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

Time Time::operator - (Time &time) {
	if (hour > time.getHour()) {
		return Time(hour - time.getHour(), \
			min - time.getMin(), \
			sec - time.getSec());
	}
	else if (hour == time.getHour()) {
		if (min > time.getMin()) {
			return Time(hour - time.getHour(), \
				min - time.getMin(), \
				sec - time.getSec());
		}
		else if (min == time.getMin()) {
			if (sec >= time.getSec()) {
				return Time(hour - time.getHour(), \
					min - time.getMin(), \
					sec - time.getSec());
			}
			else {
				return Time(time.getHour() - hour, \
					time.getMin() - min, \
					time.getSec() - sec);
			}
		}
		else {
			return Time(time.getHour() - hour, \
				time.getMin() - min, \
				time.getSec() - sec);
		}
	}
	else {
		return Time(time.getHour() - hour, \
			time.getMin() - min, \
			time.getSec() - sec);
	}

}

int main()
{
	Time time1(15, 35, 6);
	Time time2(23, 23, 1);
	
	printf("time1为：%dh %dm %ds\n", \
		time1.getHour(), time1.getMin(), time1.getSec());
	printf("time2为：%dh %dm %ds\n", \
		time2.getHour(), time2.getMin(), time2.getSec());

	if (time1 > time2) {
		printf("time1 > time2\n");
	}
	else if (time1 < time2) {
		printf("time1 < time2\n");
	}
	else if (time1 == time2) {
		printf("time1 == time2\n");
	}

	printf("time1 与 time2 的时间差是：%dh %dm %ds\n", \
		(time1 - time2).getHour(), \
		(time1 - time2).getMin(), \
		(time1 - time2).getSec());

	system("PAUSE");
	return 0;

}


