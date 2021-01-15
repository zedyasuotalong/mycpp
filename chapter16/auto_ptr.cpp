#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <algorithm>

class Report
{
	private:
		std::string str;
	public:
		Report(const std::string & s):str(s) {std::cout<<"Object Created.\n";}
		~Report() {std::cout<<"Object Deleted.\n";}
		void show() {std::cout<<str<<std::endl;}
};
void basic_test()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->show();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->show();
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->show();
	}
}
void implicit_explicit_test()
{
	std::shared_ptr<double> pd;
	double *p_reg = new double[20];
	for (int i=0; i<20; i++)
		p_reg[i] = i+0.1;
	std::cout<<"regular print:\n";
	for (int i=0; i<20; i++)
		std::cout<<p_reg[i]<<' ';
	std::cout<<std::endl;
//	pd = p_reg;		//now allow implicit
	pd = std::shared_ptr<double>(p_reg);	//allowed, explicit assign operator
//	std::shared_ptr<double> pshared = p_reg;	//not allow implicit
//	std::shared_ptr<double> psharedi2(p_reg);	//allowed, explicit copy constructor
#if 0
	//error usage
	std::cout<<"c++11 for cycle print:\n";
	for (auto & x : pd)
		std::cout<<x<<' ';
	//error usage, no operator[] for shared_ptr
	std::cout<<"shared_ptr print:\n";
	for (int i=0; i<20; i++)
		std::cout<<pd[i]<<' ';
#endif
}
void assignment_difference()
{
	// auto_ptr/unique_ptr/shared_ptr
	#define PTR_TYPE shared_ptr
	using namespace std;
	PTR_TYPE<string> films[5] = {
		PTR_TYPE<string> (new string("zebra")),
		PTR_TYPE<string> (new string("goose")),
		PTR_TYPE<string> (new string("cat")),
		PTR_TYPE<string> (new string("dog")),
		PTR_TYPE<string> (new string("monkey"))
	};
	PTR_TYPE<string> pwin;
	pwin = films[2];
	auto & x = films[2];
	cout<<"now print all:\n";
	for (int i=0; i<5; i++)
		cout<<*films[i]<<' ';
//	for (const auto & x : films)
//		cout<<*x<<' ';
	cout<<"\n";
	cout<<"now print pwin:\n"<<*pwin<<endl;
	cout<<"now print auto x:\n"<<*x<<endl;
	unique_ptr<string> pu1, pu2;
	//pu2 = pu1;	//not allowed	for unique_ptr
	pu1 = unique_ptr<string>(new string("asdasd"));	//allowed
}
void array_unique()
{
#undef PTR_TYPE
	#define PTR_TYPE unique_ptr
	using namespace std;
	PTR_TYPE<double []> pda(new double[5]);
	for (int i=0; i<5; i++)
		pda[i] = i+0.1;
	for (int i=0; i<5; i++)
		cout<<pda[i]<<' ';
	cout<<endl;
}
using namespace std;
unique_ptr<int> make_int(int n)
{
	return unique_ptr<int>(new int(n));
}
void show(unique_ptr<int> & pi)
{
	cout<<*pi<<' ';
}
void contain_unique()
{
	vector<unique_ptr<int>> vp(10);
	for (int i=0; i<10; i++)
		vp[i] = make_int(rand() % 1000);
	vp.push_back(make_int(rand() % 1000));
	for_each(vp.begin(), vp.end(), show);
	cout<<endl;
}
void between_unique_and_shared_ptr()
{
	unique_ptr<int> pup(make_int(rand() % 1000));	//ok
//	shared_ptr<int> spp(pup);						//non-ok	pup is an lvalue
	shared_ptr<int> spr(make_int(rand() % 1000));	//ok
}

int main()
{
	std::cout<<"*************************basic test****************************\n";
	basic_test();
	std::cout<<"*************************implicit/explicit****************************\n";
	implicit_explicit_test();
	std::cout<<"*************************assignment difference****************************\n";
	assignment_difference();
	std::cout<<"*************************array[] test****************************\n";
	array_unique();
	std::cout<<"*************************storage unique_ptr in STL container****************************\n";
	contain_unique();
	std::cout<<"*************************unique_ptr with shared_ptr****************************\n";
	between_unique_and_shared_ptr();
	return 0;
}
