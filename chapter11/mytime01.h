#ifndef __MY_TIME_H__
#define __MY_TIME_H__
#include <iostream>
class Time
{
	private:
		int hour;
		int min;
	public:
		Time(int h=0, int m=0):hour(h),min(m) {}
		void addmin(int m);
		void addhour(int h) {hour+=h;}
		void reset(int h=0, int m=0) {hour=h; min=m;}
		Time operator+(const Time & t) const;
		Time operator-(const Time & t) const;
		Time operator*(int n) const;
		friend Time operator*(int n, const Time & t);
		void show() const;
		friend std::ostream & operator<<(std::ostream & o, const Time & t);
};
#endif
