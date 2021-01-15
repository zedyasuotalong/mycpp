#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
enum SHENG {JIANGSU,YANCHENG};
enum class SHI {ASD,YANCHENG};
class Stock
{
	private:
		enum {ZED=10,YASUO,TALONG};
		std::string company;
		int share;
	public:
//		enum My_test {TESTA=10,TESTB,TESTC};
		enum {TESTA=10,TESTB,TESTC};
		Stock(const std::string co, int s = 0);
		Stock(int s);
		Stock();
		~Stock();
		void show() const {std::cout<<"[company "<<company<<", share "<<share<<']'<<std::endl;}
		const Stock & topshare(const Stock & s) const;
};
Stock::Stock()
{
	company = "unknown company";
	share = ZED;
	std::cout<<"implicit constructor! "<<company<<std::endl;
}
Stock::Stock(const std::string co, int s)
{
	company = co;
	share = s;
	std::cout<<"explicit constructor! "<<company<<std::endl;
}
Stock::Stock(int s)
{
	company = "one parameter func";
	share = s;
	std::cout<<"one parameter implicit constructor! "<<company<<std::endl;
}
Stock::~Stock()
{
	std::cout<<"bye "<<company<<std::endl;
}
const Stock & Stock::topshare(const Stock &a) const
{
	if(a.share < this->share)
		return *this;
	else
		return a;
}
int main()
{
	Stock(2).show();
	Stock s1("google", 3);
	Stock s2;
	std::cout<<"s1 show:\n";
	s1.show();
	s2 = Stock("ali", 2);
	std::cout<<"s2 show:\n";
	s2.show();
	//const Stock * s3 = &s1.topshare(s2);
	const Stock & s3 = s1.topshare(s2);
	std::cout<<"s3 show:\n";
	//s3->show();
	s3.show();
	std::cout<<"****************************"<<std::endl;
	const Stock ss[2] = {Stock("baidu", 10), Stock("zed", 100)};
	const Stock ss2[2];
	ss[0].show();
	ss[1].show();
	ss2[0].show();
	ss2[1].show();
	std::cout<<"----------------------------"<<std::endl;
//	std::cout<<"Stock TESTA="<<Stock::My_test::TESTA<<std::endl;
//	std::cout<<"Stock TESTB="<<Stock::My_test::TESTB<<std::endl;
//	std::cout<<"Stock TESTC="<<Stock::My_test::TESTC<<std::endl;
	std::cout<<"Stock TESTA="<<Stock::TESTA<<std::endl;
	std::cout<<"Stock TESTB="<<Stock::TESTB<<std::endl;
	std::cout<<"Stock TESTC="<<Stock::TESTC<<std::endl;
	
	return 0;
}
