#include "abc.h"

using namespace std;

//AcctABC methods
void AcctABC::deposit(double amt)
{
	if (amt<=0)
		cout<<"the amount to be deposit must be > 0.\n";
	else
		balance += amt;
}
void AcctABC::withDraw(double amt)
{
	balance -= amt;
}

//Brass methods
void Brass::viewAcct() const
{
	cout<<"fullName: "<<getname()<<endl;
	cout<<"number: "<<getnumber()<<endl;
	cout<<"balance: "<<getbalance()<<endl;
}
void Brass::withDraw(double amt)
{
	if (amt <= 0)
		cout<<"the amount to be withdrawed must be > 0.\n";
	else if (amt <= getbalance())
		AcctABC::withDraw(amt);
	else
		cout<<"the amount to be withdrawed exceeds the limit.\n";
}
//BrassPlus methods
void BrassPlus::viewAcct() const
{
	cout<<"fullName: "<<getname()<<endl;
	cout<<"number: "<<getnumber()<<endl;
	cout<<"balance: "<<getbalance()<<endl;
	cout<<"maxLoan: "<<maxLoan<<endl;
	cout<<"rate: "<<rate<<endl;
	cout<<"ownsBank: "<<ownsBank<<endl;
}
void BrassPlus::withDraw(double amt)
{
	double bal = getbalance();
	if (amt <= 0)
		cout<<"the amount to be withdrawed must be > 0.\n";
	else if (amt <= bal)
		AcctABC::withDraw(amt);
	else if (amt <= bal + maxLoan - ownsBank) {
		double advance = amt-bal;
		ownsBank += advance * (1 + rate);
		cout<<"Bank advance: "<<advance<<endl;
		cout<<"Advance charge: "<<advance*1.0<<endl;
		deposit(advance);	//no need to use AcctABC::deposit()
		AcctABC::withDraw(amt);
	} else
		cout<<"the amount to be withdrawed exceeds the limit.\n";
}
const int CLINT_NUMS = 4;
int main()
{
	int i = 0;
	string tmpname;
	long tmpnumber;
	double tmpbal;
	char kind;
	AcctABC *p_clients[CLINT_NUMS];
	for (i=0; i<CLINT_NUMS; i++)
	{
		cout<<"Enter client "<<i<<" name:\n";
		cin>>tmpname;
		cout<<"Enter client "<<i<<" number:\n";
		cin>>tmpnumber;
		cout<<"Enter client "<<i<<" balance:\n";
		cin>>tmpbal;
		cout<<"Enter 1 for Brass Client and 2 for BrassPlus Client:\n";
		while (cin>>kind && (kind != '1' && kind != '2'))
			cout<<"Enter either 1 or 2:\n";
		if (kind == '1')
			p_clients[i] = new Brass(tmpname, tmpnumber, tmpbal);
		else {
			double tmpmax, tmprate;
			cout<<"Enter client "<<i<<" maxLoan:\n";
			cin>>tmpmax;
			cout<<"Enter client "<<i<<" rate:\n";
			cin>>tmprate;
			p_clients[i] = new BrassPlus(tmpname, tmpnumber, tmpbal, tmpmax, tmprate);
		}
	}
	for (i=0; i<CLINT_NUMS; i++)
	{
		p_clients[i]->viewAcct();
	}
	for (i=0; i<CLINT_NUMS; i++)
	{
		delete p_clients[i];
	}
	return 0;
}
