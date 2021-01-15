#include <iostream>
#include "mytime01.h"

void Time::addmin(int m)
{
	int mins = hour * 60 + min + m;
	hour = mins/60;
	min = mins%60;
}
Time Time::operator+(const Time &t) const
{
	Time ret;
	int mins = this->min + t.min;
	ret.hour = this->hour + t.hour + mins/60;
	ret.min = mins%60;

	return ret;
}
Time Time::operator-(const Time &t) const
{
	Time ret;
	int t1,t2;
	t1 = (this->hour * 60 + this->min);
	t2 = (t.hour * 60 + t.min);

	ret.hour = (t1-t2)/60;
	ret.min = (t1-t2)%60;

	return ret;
}
Time Time::operator*(int n) const
{
	Time ret;
	long mins = n * (hour*60 + min);
	ret.hour = mins / 60;
	ret.min = mins % 60;

	return ret;
}
Time operator*(int n, const Time & t)
{
	Time ret;
	long mins = n * (t.hour * 60 + t.min);
	ret.hour = mins / 60;
	ret.min = mins % 60;

	return ret;
}
void Time::show()const
{
	std::cout<<"Time: "<<hour<<" hours, "<<min<<" minutes"<<std::endl;
}
std::ostream & operator<<(std::ostream & o, const Time &t)
{
	o<<"Time: "<<t.hour<<" hours, "<<t.min<<" minutes";
	return o;
}

int main()
{
	Time planning;
	Time coding(1, 20);
	Time fixing(3, 45);
	Time fxxing(6, 95);
	planning.show();
	coding.show();
	fixing.show();
	fxxing.show();
	std::cout<<"test operator+\n";
	Time total = coding + fixing + fxxing;
	std::cout<<total<<std::endl;
	std::cout<<"test operator-\n";
	Time sub = fxxing - coding;
	std::cout<<sub<<std::endl;
	std::cout<<"test operator*\n";
	Time mul = coding * 5;
	std::cout<<mul<<std::endl;
	std::cout<<"test friend operator*\n";
	Time mul_ = 5 * coding;
	std::cout<<mul<<std::endl;
	std::cout<<"test friend operator<<\n";
	std::cout<<coding<<fixing<<fxxing<<std::endl;
	return 0;
}
