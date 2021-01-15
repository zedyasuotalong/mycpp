#include <iostream>
#include <string>
#include <cstring>
//#include <cmath>
using namespace std;
const int CLIENT = 4;
#if 1
/*************************Class about DMA***************************/
class baseDMA 
{
	private:
		char *label;
		int rating;
	public:
		baseDMA(const char *m = "null", int r = 0);
		baseDMA(const baseDMA & b);
		virtual ~baseDMA() {delete [] label;}
		baseDMA & operator=(const baseDMA & b);
		friend ostream & operator<<(ostream & os, const baseDMA & bs);
};
baseDMA::baseDMA(const char *m, int r) {
	label = new char[strlen(m) + 1];
	strcpy(label, m);
	rating = r;
}
baseDMA::baseDMA(const baseDMA & b) {
	label = new char[strlen(b.label) + 1];
	strcpy(label, b.label);
	rating = b.rating;
}
baseDMA & baseDMA::operator=(const baseDMA & b)
{
	if (this == &b)
		return *this;
	delete [] label;
	label = new char[strlen(b.label)+1];
	strcpy(label, b.label);
	rating = b.rating;
	return *this;
}
class lacksDMA : public baseDMA
{
	private:
		char color[16];
	public:
		lacksDMA(const char *m = "null", int r = 0, const char * c = "red"):baseDMA(m, r) {strncpy(color, c, 15);}
		lacksDMA(const baseDMA & bs, const char *c = "red"):baseDMA(bs) {strncpy(color, c, 15);}
		friend ostream & operator<<(ostream & os, const lacksDMA & ls);
};
class hasDMA : public baseDMA
{
	private:
		char *style;
	public:
		hasDMA(const char * m = "NULL", int r = 0, const char *s = "red");
		hasDMA(const hasDMA & hs);
		virtual ~hasDMA() { delete [] style;}
		hasDMA & operator=(const hasDMA & hs);
		friend ostream & operator<<(ostream & os, const hasDMA & hs);
};
hasDMA::hasDMA(const char *m, int r, const char *s):baseDMA(m,r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA & hs) :baseDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);
	delete [] style;
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
	return *this;
}
//friend function
ostream & operator<<(ostream & os, const baseDMA & bs)
{
	os<<"Label: "<<bs.label<<endl;
	os<<"Rating: "<<bs.rating<<endl;
	return os;
}
ostream & operator<<(ostream & os, const lacksDMA & ls)
{
	os<<(baseDMA & )ls;
	os<<"Color: "<<ls.color<<endl;
	return os;
}
ostream & operator<<(ostream & os, const hasDMA & hs)
{
	os<<(baseDMA & )hs;
	os<<"Style: "<<hs.style<<endl;
	return os;
}
int main() {
	baseDMA base("zed", 3);
	lacksDMA lack("yasuo", 4, "green");
	hasDMA has("talong", 5, "blue");
	cout<<"Display baseDMA object:\n";
	cout<<base;
	cout<<"Display lacksDMA object:\n";
	cout<<lack;
	cout<<"Display hasDMA object:\n";
	cout<<has;
	lacksDMA lack2(lack);
	cout<<"Result of lacksDMA copy:\n";
	cout<<lack2;
	hasDMA has2;
	has2 = has;
	cout<<"Resule of hasDMA assignment:\n";
	cout<<has2;
	return 0;
}
#endif
/*************************Class Abstract Base Class***************************/
#if 0
class AcctABC {
	private:
		string name;
		long number;
		double balance;
	protected:
		const string & Name() const {return name;}
		long Number() const {return number;}
	public:
		AcctABC(const string & n = "nobody", long no = -1, double b = 0.0):name(n),number(no),balance(b) {}
		void Deposit (double amt);
		virtual void Withdraw(double amt) =0;
		double Balance() const { return balance; }
		virtual void ViewAcct() const =0;
		virtual ~AcctABC() {}
};
class Brass : public AcctABC {
	public:
		Brass(const string & n = "nobody", long no = -1, double b = 0.0):AcctABC(n,no,b) {}
		virtual void Withdraw(double amt);
		virtual void ViewAcct() const;
		virtual ~Brass() {}
};
class BrassPlus : public AcctABC {
class lacksDMA : public baseDMA
{
	private:
		char color[16];
	public:
}
class hasDMA : public baseDMA
{
	private:
		char *style;
	public:
		hasDMA(const char * m = "NULL", int r = 0, char *s = "red"):baseDMA(m, r)
}
#endif
/*************************Class Abstract Base Class***************************/
#if 0
class AcctABC {
	private:
		string name;
		long number;
		double balance;
	protected:
		const string & Name() const {return name;}
		long Number() const {return number;}
	public:
		AcctABC(const string & n = "nobody", long no = -1, double b = 0.0):name(n),number(no),balance(b) {}
		void Deposit (double amt);
		virtual void Withdraw(double amt) =0;
		double Balance() const { return balance; }
		virtual void ViewAcct() const =0;
		virtual ~AcctABC() {}
};
class Brass : public AcctABC {
	public:
		Brass(const string & n = "nobody", long no = -1, double b = 0.0):AcctABC(n,no,b) {}
		virtual void Withdraw(double amt);
		virtual void ViewAcct() const;
		virtual ~Brass() {}
};
class BrassPlus : public AcctABC {
	private:
		double maxLoan;
		double rate;
		double owesBank;
	public:
		BrassPlus(const string & n = "nobody", long no = -1, double b = 0.0, double ml = 500, double r = 0.10, double ob = 0.0):AcctABC(n, no, b),maxLoan(ml),rate(r),owesBank(ob){}
		BrassPlus(const Brass & b, double ml = 500, double r = 0.10, double ob = 0.0):AcctABC(b),maxLoan(ml),rate(r),owesBank(ob) {}
		virtual void Withdraw(double amt);
		virtual void ViewAcct() const;
		void ResetMax(double m) {maxLoan = m;}
		void ResetRate(double r) {rate = r;}
		void ResetOB(double o) {owesBank = o;}
};
void AcctABC::Deposit(double amt) {
	if (amt < 0)
		cout<<"Invalid deposit !\n";
	else
		balance += amt;
}
void AcctABC::Withdraw(double amt) {
	balance -= amt;
}
void Brass::Withdraw(double amt) {
	if (amt<0) 
		cout<<"Invalid Brass withdraw\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout<<"Amt exceeds your balance!\n";
}
void Brass::ViewAcct() const {
	cout<<"ClientName : "<<Name()<<endl;
	cout<<"ClientNumber : "<<Number()<<endl;
	cout<<"ClientBalance : "<<Balance()<<endl;
}
void BrassPlus::Withdraw(double amt) {
	double bal = Balance();
	if (amt <= bal) 
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank) {
		double a = amt - bal;
		owesBank += a*(1.0 + rate);
		Deposit(a);
		AcctABC::Withdraw(amt);
	} else 
		cout<<"Invalid BrassPlus withdraw\n";
}
void BrassPlus::ViewAcct() const {
	cout<<"ClientName : "<<Name()<<endl;
	cout<<"ClientNumber : "<<Number()<<endl;
	cout<<"ClientBalance : "<<Balance()<<endl;
	cout<<"ClientMaxloan : "<<maxLoan<<endl;
	cout<<"ClientRate : "<<rate<<endl;
	cout<<"ClientOwesBank : "<<owesBank<<endl;
}
int main()
{
	AcctABC * p [CLIENT] = {NULL};
	p[0] = new Brass("zed", 1123, 400);
	p[1] = new BrassPlus("yasuo", 1124, 700);
	cout<<"****************CLIENT 1******************\n";
	p[0]->ViewAcct();
	p[0]->Deposit(200);
	p[0]->ViewAcct();
	p[0]->Withdraw(500);
	p[0]->ViewAcct();
	p[0]->Withdraw(200);
	cout<<"****************CLIENT 2******************\n";
	p[1]->ViewAcct();
	p[1]->Deposit(200);
	p[1]->ViewAcct();
	p[1]->Withdraw(500);
	p[1]->ViewAcct();
	p[1]->Withdraw(500);
	p[1]->ViewAcct();
	return 0;
}
#endif
/*************************Class TableTennisPlayer***************************/
#if 0
class TableTennisPlayer {
	private:
		string firstname;
		string lastname;
		bool hasTable;
	public:
		TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false):firstname(fn),lastname(ln),hasTable(ht) {}
		void Name() const {cout<<firstname<<","<<lastname;}
		friend ostream & operator<<(ostream & os, const TableTennisPlayer & p);
		bool HasTable() const {return hasTable;}
		void ResetTable(bool v) {hasTable = v;}
		virtual void show( int n ) const {cout<<"Base : "<<n<<endl;}
		virtual void show( ) const {cout<<"Base : "<<endl;}
		TableTennisPlayer & build(int n) {cout<<"Base build:"<<n<<endl;}
};
ostream & operator<<(ostream & os, const TableTennisPlayer & p) {
	os<<p.firstname<<","<<p.lastname;
	return os;
}

class RatedPlayer : public TableTennisPlayer {
	private:
		int rating;
	public:
		RatedPlayer(int a, const string & fn = "none", const string & ln = "none", bool ht = false):rating(a),TableTennisPlayer(fn,ln,ht){}
		RatedPlayer(int a, const TableTennisPlayer & tp):rating(a),TableTennisPlayer(tp) {}
		int Rating() const { return rating; }
		void ResetRating(int r) {rating = r;}
		virtual void show(int n) const {cout<<"Derived "<<endl;}
		virtual void show() const {cout<<"Derived "<<endl;}
		RatedPlayer & build(int n) {cout<<"derivited build:"<<n<<endl;}
};
/*************************Class Brass***************************/
class Brass {
	private:
		string name;
		long acctNum;
		double balance;
	public:
		Brass(const string & s = "none", long a = -1, double b = 0.0):name(s),acctNum(a),balance(b) {}
		void Deposit(double amt);
		virtual void Withdraw(double amt);
		double Balance() const;
		virtual void ViewAcct() const;
		virtual ~Brass();
};
class BrassPlus : public Brass {
	private:
		double maxLoan;
		double rate;
		double owesBank;
	public:
		BrassPlus(const string & s = "none", long a = -1, double b = 0.0, double m = 500, double r = 0.11125):Brass(s,a,b),maxLoan(m),rate(r) {}
		BrassPlus(const Brass & b, double m = 500, double r = 0.11125):Brass(b),maxLoan(m),rate(r) {}
};
int main()
{
	TableTennisPlayer p1("zed", "liu", true);
	p1.Name();
	cout<<endl;
	RatedPlayer p2(12, "yasuo", "zhang", false);
	p2.Name();
	cout<<endl;
	TableTennisPlayer * p = &p1;
	p->Name();
	cout<<endl;
	p2.show();
//	p2.show(5);   //invalid
//	p1.build(10);	//valid
//	p2.build(20);	//valid

	return 0;
}
#endif
