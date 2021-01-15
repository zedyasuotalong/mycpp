#include "dma.h"
#include <cstring>
using namespace std;
baseDMA::baseDMA(const char *l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rate = r;
}
baseDMA::baseDMA(const baseDMA & b)
{
	label = new char[strlen(b.label) + 1];
	strcpy(label, b.label);
	rate = b.rate;
}
baseDMA::~baseDMA()
{
	delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA &b)
{
	if (this == &b)
		return *this;
	delete [] label;
	label = new char[strlen(b.label) + 1];
	strcpy(label, b.label);
	rate = b.rate;

	return *this;
}
std::ostream & operator<<(std::ostream & o, const baseDMA & b)
{
	o<<"label: "<<b.label<<", rate: "<<b.rate;
	return o;
}
lacksDMA::lacksDMA(const char *c, const char *l, int r):baseDMA(l,r)
{
	strcpy(color, c);
}
lacksDMA::lacksDMA(const char *c, const baseDMA &b):baseDMA(b)
{
	strcpy(color, c);
}
std::ostream & operator<<(std::ostream & o, const lacksDMA & l)
{
	o<<(const baseDMA &)l;
	o<<", color:"<<l.color;
	return o;
}
hasDMA::hasDMA(const char *s, const char *l, int r):baseDMA(l,r)
{
	style = new char[strlen(s)+1];
	strcpy(style, s);
}
hasDMA::hasDMA(const char *s, const baseDMA &b):baseDMA(b)
{
	style = new char[strlen(s)+1];
	strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &h):baseDMA(h)
{
	cout<<__func__<<endl;
	style = new char[strlen(h.style)+1];
	strcpy(style, h.style);
}
hasDMA::~hasDMA()
{
	delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA &h)
{
	cout<<__func__<<endl;
	if (this == &h)
		return *this;
	baseDMA::operator=(h);
	delete [] style;
	style = new char[strlen(h.style)+1];
	strcpy(style, h.style);

	return *this;
}
std::ostream & operator<<(std::ostream & o, const hasDMA & h)
{
	o<<(const baseDMA &)h;
	o<<", style:"<<h.style;
	return o;
}

int main()
{
	baseDMA b1("base1", 1);
	lacksDMA l1("lacks1", "bbbb1", 11);
	hasDMA h1("has1", "bbbbbbbbbb1", 111);
	cout<<"baseDMA1: "<<b1<<endl;
	cout<<"lacksDMA1: "<<l1<<endl;
	cout<<"hasDMA1: "<<h1<<endl;
	lacksDMA l2(l1), l3;
	cout<<"lacksDMA copy:\n"<<l2<<endl;
	l3 = l2;
	cout<<"lacksDMA assign:\n"<<l3<<endl;
	
	hasDMA h2(h1), h3;
	cout<<"hasDMA copy:\n"<<h2<<endl;
	h3 = h2;
	cout<<"hasDMA assign:\n"<<h3<<endl;
	baseDMA *pb;
	hasDMA *ph;
	pb = &h1;
	ph = dynamic_cast<hasDMA *>(pb);
	cout<<"dynamic_cast ok:\n";
	cout<<"ph address: "<<ph<<endl;
	pb = &b1;
	ph = static_cast<hasDMA *>(pb);
	cout<<"dynamic_cast non-ok:\n";
	cout<<"ph address: "<<ph<<endl;
	return 0;
}
