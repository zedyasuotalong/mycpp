#include <iostream>
using namespace std;
class Complex
{
	private:
		double r;
		double i;
	public:
		Complex(double x=0, double y=0):r(x),i(y) {}
		Complex operator+(Complex & c) const;
		Complex operator-(Complex & c) const;
		Complex operator*(Complex & c) const;
		Complex operator~() const;
		operator double() const;
		friend Complex operator*(double x, Complex c);
		friend ostream & operator<<(ostream & o, const Complex & c);
		friend istream & operator>>(istream & i, Complex & c);
};
Complex Complex::operator+(Complex & c) const
{
	return Complex(r+c.r, i+c.i);
}
Complex Complex::operator-(Complex & c) const
{
	return Complex(r-c.r, i-c.i);
}
Complex Complex::operator*(Complex & c) const
{
	return Complex(r*c.r-i*c.i, r*c.i+i*c.r);
}
Complex Complex::operator~() const
{
	return Complex(r, i*-1.0);
}
Complex::operator double() const
{
	return r;
}
Complex operator*(double x, Complex c)
{
	return Complex(x*c.r, x*c.i);
}
ostream & operator<<(ostream & o, const Complex & c)
{
	o<<"("<<c.r<<","<<c.i<<")";
	return o;
}
istream & operator>>(istream & i, Complex & c)
{
	i>>c.r>>c.i;
	return i;
}
int main()
{
	Complex a(3.0, 4.0);
	Complex c;
	c = 5.1;
	double z = c;
	cout<<"c is "<<c<<endl;
	cout<<"z is "<<z<<endl;
	cout<<"Enter a complex number(q to quit):\n";
	while (cin>>c) {
		cout<<"c is "<<c<<endl;
		cout<<"-c is "<<~c<<endl;
		cout<<"a + c is "<<a+c<<endl;
		cout<<"a - c is "<<a-c<<endl;
		cout<<"a * c is "<<a*c<<endl;
		cout<<"2 * c is "<<2*c<<endl;
		cout<<"Enter a complex number(q to quit):\n";
	}
	cout<<"Done!\n";
	return 0;
}
