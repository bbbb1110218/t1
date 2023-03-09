#ifndef __BRASS_H__
#define __BRASS_H__
#include <string>
#include <iostream>

using namespace std;

class Brass{
private:
	string fullName;	//名字
	long acctNum; 		//账号
	double balance;		//余额
public:
	Brass(const string&s="nobody",long an=-1,double bal=0.0);
	void Deposit(double amt);			//存款
	virtual void Withdraw(double amt);	//取款
	double Balance()const;  			//显示余额
	virtual void ViewAcct()const; 		//显示全部

};


class BrassPlus:public Brass{
private:
	double maxLoad ;	//透支上限
	double rate_;		//透支利率
	double owesBank;	//当前投资总额
public:
	BrassPlus(const string&s="nobody",long an=-1,double bal=0.0,
		double ml=500.0,double rate=0.11125,double ow=0.0); //派生类构造函数

	BrassPlus(const Brass&br,double ml=500.0,double rate=0.11125,double ow=0.0);
	virtual void ViewAcct()const;	//方法重写;
	virtual void Withdraw(double amt);  //取款
	void ResetMax(double m){maxLoad=m;}
	void ResetRate(double r){rate_=r;}
	void ResetOwes(){owesBank=0.0;}


};




#endif 