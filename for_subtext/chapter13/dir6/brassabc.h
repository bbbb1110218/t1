#ifndef __BRASSABC_H__
#define __BRASSABC_H__

#include <iostream>
#include <string>

using namespace std;

class Braabc{
private:
	string fullname_;
	long accnum_;
	double amount_;
protected:
	const string& Fullname()const{return fullname_;}
	const long Accnum()const{return accnum_;}
	const double Amount()const{return amount_;}
public:
	Braabc(const string &fullname,long accnum,double amount):fullname_(fullname),
									accnum_(accnum),amount_(amount){}
	virtual ~Braabc(){}
	virtual void save(double amt){if(amt >=0) amount_+=amt;else cout <<"can't be negative\n";};
	virtual void withdraw(double amt)=0;
	virtual void show()const=0;

};

class Brass:public Braabc{
public:
	Brass(const string &fullname="None",long accnum=-1,double amount=0.0):Braabc(fullname,accnum,amount){};
	virtual void withdraw(double amt);
	virtual void show()const;
	virtual ~Brass(){}
};

class BrassPlus:public Braabc{

private:
	double topmax_;
	double rate_;
	double loans_;
	void ChangeLoads(double amt){if(amt >0) loans_ -=amt;}; 
	void refund ();//尝试还钱


public:
	BrassPlus(const string &fullname="None",long accnum=-1,double amount=0.0,double topmax=500,double rate=0.1123,double loans=0.0);
	virtual ~BrassPlus(){}
	virtual void withdraw(double amt);
	virtual void show()const;

	

	double Topmax(){return topmax_;}
	double Rate(){return rate_;}
	double Loans(){return loans_;}
	virtual void save(double amt);


};



#endif