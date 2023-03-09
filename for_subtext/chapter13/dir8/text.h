#ifndef __TEXT_H__
#define __TEXT_H__


#include <iostream>
using namespace std;


class BaseABC{	//基类
private:
	char *name_;
	int age_;
public:
	BaseABC(const char *name,int age);
	BaseABC(const BaseABC& ba);
	virtual ~BaseABC();
	char *Name()const{return name_;}
	int Age()const{return age_;}
	virtual BaseABC& operator=(const BaseABC&ot);
	friend ostream& operator<<(ostream &os,const BaseABC& ba);
	virtual void show();
};


class Person:public BaseABC{
private:
	char * hobby_; //爱好
	double height_;  //身高 
	double weight_; //体重

public:
	Person(const char *name="None",int age=0, const char * hobby ="None",double height=0.0,double weight=0.0);
	Person(const BaseABC& ba,const char * hobby ="None",double height=0.0,double weight=0.0);
	Person(const Person &pe);
	virtual ~Person();
	virtual Person& operator=(const Person& pe);
	friend ostream& operator<<(ostream &os,const Person& pe);
	virtual void show();

};


#endif