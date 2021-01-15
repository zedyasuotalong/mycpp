#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#if 0
/*************************Class Time***************************/
class Time {
	private:
		int hours;
		int minites;
	public:
		Time(int h=0, int m=0):hours(h),minites(m) {}
		void addMin(int m) ;
		void addHour(int h) { hours += h;}
		void reset(int h=0, int m=0){hours = h; minites = m;}
		Time operator+(const Time & t) const;
		Time operator-(const Time & t) const;
		Time operator*(int t) const;
		friend Time operator*(int n, const Time &t) ;
		void show() const;
		friend ostream & operator<<(ostream & os, const Time &t);
};
void Time::addMin(int m) {
	minites += m;
	hours += minites/60;
	minites %= 60;
}
Time Time::operator+(const Time &t) const {
	Time tmp;
	tmp.minites = this->minites + t.minites;
	tmp.hours = this->hours + t.hours + tmp.minites/60;
	tmp.minites %= 60;

	return tmp;
}
Time Time::operator-(const Time &t) const {
	Time tmp;
	int t1, t2;
	t1 = this->hours * 60 + this->minites;
	t2 = t.hours * 60 + t.minites;
	tmp.minites = (t1 - t2) % 60;
	tmp.hours = (t1 - t2)/60;

	return tmp;
}
Time operator*(int n, const Time & t) {
	Time tmp;
	long mins = t.hours * n * 60 + t.minites * n;
	tmp.hours = mins / 60;
	tmp.minites = mins % 60;

	return tmp;
}
Time Time::operator*(int t) const {
	Time tmp;
	long mins = hours * t * 60 + minites * t;
	tmp.hours = mins / 60;
	tmp.minites = mins % 60;

	return tmp;
}
void Time::show() const {
	cout<<hours<<" hours, "<<minites<<" minites.\n";
}
ostream & operator<<(ostream & os, const Time &t) {
	os<<t.hours<<" hours, "<<t.minites<<" minites.\n";
	return os;
}

int main()
{
	Time planning;
	Time coding(2, 40);
	Time fixing(14, 55);
	Time fxxing(22, 95);
	planning.show();
	coding.show();
	fixing.show();
	fxxing.show();
	cout<<"test operator+:\n";
	Time total = coding + fixing + fxxing;
	total.show();
	cout<<"test operator-:\n";
	Time sub = coding - fixing;
	sub.show();
	cout<<"test operator*:\n";
	Time mul = coding * 3;
	mul.show();
	cout<<"test friend operator*:\n";
	Time mul_f = 3 * coding;
	mul_f.show();
	cout<<"test friend operator++:\n";
	cout<<coding<<fixing<<mul_f;
	return 0;
}
#else
/*************************Class Vector***************************/
namespace VECTOR
{
	class Vector {
		public:
			enum Mode {RECT, POL};
		private:
			double x=0.0;
			double y;
			double mag;
			double ang;
			Mode mode;
			void set_x();
			void set_y();
			void set_mag();
			void set_ang();
		public:
			explicit Vector(double n1 = 0, double n2 = 0, Mode form = RECT);
			void reset(double n1 = 0, double n2 = 0, Mode form = RECT);
			double xVal() const { return x;}
			double yVal() const { return y;}
			double magVal() const { return mag;}
			double angVal() const { return ang;}
			void rect_mode(){mode = RECT;}
			void polar_mode(){mode = POL;}
			//operator overloading
			Vector operator+(const Vector & v) const;
			Vector operator-(const Vector & v) const;
			Vector operator-() const;
			Vector operator*(double n) const;
			explicit operator double() const;
			explicit operator int() const;
			explicit operator float() const;
			//friends
			friend Vector operator*(double n, const Vector & v);
			friend ostream & operator<<(ostream & os, const Vector & v);
	};
}
namespace VECTOR
{
	const double RAD_TO_DEG = 45.0 / atan(1.0);
	//private methods
	//set x,y from polar coordinate
	void Vector::set_x() {
		x = mag * cos(ang);
	}
	void Vector::set_y() {
		y = mag * sin(ang);
	}
	//set magnitude,angle from x,y
	void Vector::set_mag() {
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang() {
		if (x==0 && y==0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;
		if (mode == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		} else if (mode == POL) {
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		} else {
			cout<<"Vector constructor params error:\n";
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;
		if (mode == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		} else if (mode == POL) {
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		} else {
			cout<<"Vector constructor params error:\n";
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}
	Vector Vector::operator+(const Vector & v) const {
		return Vector(this->x+v.x, this->y+v.y);
	}
	Vector Vector::operator-(const Vector & v) const {
		return Vector(this->x-v.x, this->y-v.y);
	}
	Vector Vector::operator-() const {
		return Vector(-this->x, -this->y);
	}
	Vector Vector::operator*(double n) const {
		return Vector(this->x * n, this->y * n);
	}
	Vector operator*(double n, const Vector & v) {
		return Vector(n*v.x, n*v.y);	//convert n times Vector to Vector times n
	}
	ostream & operator<<(ostream & os, const Vector & v) {
		if (v.mode == Vector::RECT)
			os<<"(x, y) = ("<<v.x<<", "<<v.y<< ")";
		else if (v.mode == Vector::POL)
			os<<"(m, a) = ("<<v.mag<<", "<<v.ang*VECTOR::RAD_TO_DEG<<")";
		else
			os<<"Vector object is valid";
		return os;
	}
	Vector::operator double() const {
		cout<<"this is operator double\n";
		return x;
	}
	Vector::operator int() const {
		cout<<"this is operator int\n";
		return (int)x;
	}
	Vector::operator float() const {
		cout<<"this is operator float\n";
		return (float)x;
	}
}
int main()
{
	using namespace VECTOR;
	Vector v1(1.1, 1.2, (Vector::Mode)2);
	cout<<v1<<endl;
	Vector a = (Vector)3.7;
	cout<<a<<endl;
	float b = (float)a;
	int c = (double)a;
	cout<<"b = "<<b<<", c = "<<c<<endl;
	return 0;
}
#endif
