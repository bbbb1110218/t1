#ifndef __BRASS_H__
#define __BRASS_H__
#include <iostream>
using namespace std;


class Brass{
private:
	char * fullname_;
	long accnum_;  //账户
	double amount_;
public:
	Brass(const char *fullname,long accnum=-1,double amount=0.0);
	Brass(const Brass& br);
	virtual ~Brass();

	bool save(double amt);
	virtual bool withdraw(double amt);
	void changename(const char * new_name);
	double get_amount(){return amount_;}
	virtual void show();
};

class BrassPlus:public Brass{
private:
	char * alias_;
	double limit_; //额度
	double rate_;	//利率
	double debt_;	//欠款

public:
	BrassPlus(const char *fullname,const char * alias="None",long accnum=-1,
		double amount=0.0, double limit=500.0,double rate=0.11134,double debt=0.0);

	BrassPlus(const Brass &br,const char *alias="None",double limit=500.0,double rate=0.11134,double debt=0.0);
	
	~BrassPlus();
	void changealias(const char* new_alias);

	virtual bool withdraw(double amt);
	virtual void show();



};


#endif