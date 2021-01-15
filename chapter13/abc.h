#ifndef __ABC_H__
#define __ABC_H__
#include <iostream>
#include <string>
class AcctABC
{
	private:
		std::string fullName;
		long number;
		double balance;
	protected:
		const std::string & getname() const {return fullName;}
		long getnumber() const {return number;}
	public:
		AcctABC(std::string name="nullbody", long no=-1, double b=0.0):fullName(name),number(no),balance(b) {}
		void deposit(double amt);
		virtual void viewAcct() const =0;
		virtual void withDraw(double amt) =0;
		double getbalance() const { return balance; }
		virtual ~AcctABC() {}
};
class Brass : public AcctABC
{
	public:
		Brass(std::string name="nullbody", long no=-1, double b=0.0):AcctABC(name,no,b) {}
		virtual void viewAcct() const;
		virtual void withDraw(double amt);
		virtual ~Brass() {}
};
class BrassPlus : public AcctABC
{
	private:
		double maxLoan;
		double rate;
		double ownsBank;
	public:
		BrassPlus(std::string name="nullbody", long no=-1, double b=0.0, double ml=500, double r=0.1):AcctABC(name,no,b),maxLoan(ml),rate(r) {ownsBank=0.0;}
		BrassPlus(const Brass & b, double ml=500, double r=0.1):AcctABC(b),maxLoan(ml),rate(r) {ownsBank=0.0;}
		virtual void viewAcct() const;
		virtual void withDraw(double amt);
		virtual ~BrassPlus() {}
		void resetmax(double ml) {maxLoan = ml;}
		void resetrate(double r) {rate = r;}
		void resetowns() {ownsBank = 0.0;}
};
#endif
