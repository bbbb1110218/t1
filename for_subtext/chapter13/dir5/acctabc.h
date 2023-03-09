#ifndef __ACCTABC_H__
#define __ACCTABC_H__
#include <string>
#include <iostream>

using namespace std;

class Acctabc{				//抽象基类：不能被实例话，只能被继承
private:
	string fullName;		//三个私有变量，公共的部分抽取出来
	long acctNum;
	double balance;

protected:				//被保护的方法,派生类可以直接使用
	 const string& FullName()const{return fullName;}   //第一个const不写会出错 ⚠️不知道啥原因
	 long AcctNum()const{return acctNum;}

public:
	Acctabc(const string&s="Nullbody",long an=-1,double ba=0.0):fullName(s),acctNum(an),balance(ba){};
																//成员初始化
	void Deposit(double amt);					//所有通用方法，直接写出来就完事了
	virtual void Withdraw(double amt)=0;		//存虚函数 =0,可以定义也可以不定义
	double Balance()const{return balance;}		//公共的方法，抽取出来
	virtual void ViewAcct()const =0;			//一定会被重新写的函数,定义成虚函数 后面加0，写不可定义都ok
	virtual ~Acctabc(){} 						//虚函数析构函数
};



class Brass:public Acctabc{					//第一个继承的类 没有私有变量，直接继承抽象基类


public:
	Brass(const string&s="Nullbody",long an=-1,double ba=0.0):Acctabc(s,an,ba){};
	virtual void Withdraw(double amt);	//取款
	virtual void ViewAcct()const; 		//显示全部
	virtual ~Brass(){} 					//虚函数析构函数 最好也写上


};


class BrassPlus:public Acctabc{		//第二个派生类,继承抽象积累
private:						//新增加的三个成员变量，也被定义成私有变量
	double maxLoad ;			//透支上限
	double rate_;				//透支利率
	double owesBank;			//当前投资总额
public:
	BrassPlus(const string&s="nobody",long an=-1,double bal=0.0,
		double ml=500.0,double rate=0.11125,double ow=0.0); //派生类构造函数


	BrassPlus(const Acctabc&br,double ml=500.0,double rate=0.11125,double ow=0.0);  
											//这个方法其实用不上，因为抽象基类不能被实例话，所有没有他的引用
	virtual void ViewAcct()const;			//方法重写;

	virtual void Withdraw(double amt);  	//取款
	void ResetMax(double m){maxLoad=m;}
	void ResetRate(double r){rate_=r;}
	void ResetOwes(){owesBank=0.0;}
	virtual ~BrassPlus(){} 				//最好也加一个虚析构函数，反正没什么错


};




#endif 