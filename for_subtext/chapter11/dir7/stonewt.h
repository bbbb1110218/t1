
//Create by MacbookPro on 2022/11/23

#ifndef __STONEWT_H__
#define __STONEWT_H__

#include <iostream>
using namespace std;

class Stonewt{
private:
	enum {Lbs_per_stn=14};
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn,double lbs);
	Stonewt();
	operator int() const;  					//转换函数 转换成int 类型
	Stonewt operator*(const double &n);
	explicit operator double() const;//转换成double 类型，不能用隐式转换，
	explicit operator string() const;//转换成string 类型，不能用隐式转换，
	void show_lbs() const;
	void show_stn() const;

	friend Stonewt operator*(const double&n,const Stonewt &s);

	friend Stonewt operator+(const Stonewt &s1,const Stonewt &s2);
	
};


#endif