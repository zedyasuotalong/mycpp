#include <iostream>
#include <cstring>
#include "exercise.h"

Cow::Cow()
{
	std::cout<<"default constructor: ";
	std::strcpy(name, "c++");
	hobby = new char[20];
	std::strcpy(hobby, "coding");
	weight = 60;
	std::cout<<"\""<<name<<"\"\n";
}
Cow::Cow(const char *nm, const char *hb, double wt)
{
	std::cout<<"explicit constructor: ";
	std::strcpy(name, nm);
	hobby = new char[std::strlen(hb)+1];
	std::strcpy(hobby, hb);
	weight = wt;
	std::cout<<"\""<<name<<"\"\n";
}
Cow::Cow(const Cow &c)
{
	std::cout<<"copy constructor: ";
	std::strcpy(name, c.name);
	hobby = new char[std::strlen(c.hobby)+1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
	std::cout<<"\""<<name<<"\"\n";
}
Cow::~Cow()
{
	std::cout<<"detructor: delete \""<<name<<"\"\n";
	delete [] hobby;
}
Cow & Cow::operator=(const Cow & c)
{
	if (&c == this)
		return *this;
	delete [] hobby;
	hobby = new char[std::strlen(c.hobby)+1];
	std::strcpy(hobby, c.hobby);
	std::strcpy(name, c.name);
	weight = c.weight;
	std::cout<<"assign operator=: \""<<name<<"\"\n";
}
void Cow::ShowCow() const
{
	std::cout<<"INFO: "<<name<<","<<hobby<<","<<weight<<std::endl;
}
int main()
{
	Cow c1;
	c1.ShowCow();
	Cow c2("zed", "learning", 75);
	c2.ShowCow();

	std::cout<<"**********test copy constructor***********\n";
	Cow c3(c2);
	c3.ShowCow();

	std::cout<<"**********test assign operator=***********\n";
	c3 = c1;
	c3.ShowCow();

	std::cout<<"*****************************************\n";
	Cow *c4 = new Cow(c2);
	c4->ShowCow();
	delete c4;
	
	return 0;
}
