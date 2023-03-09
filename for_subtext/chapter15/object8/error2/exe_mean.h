//定义的两个 定义异常的类

#ifndef __EXE__MEAN_H__
#define __EXE__MEAN_H__
#include <iostream>
using namespace std;


class Bad_heam{
private:
	double v1;
	double v2;
public:
	Bad_heam(double a=0.0,double b=0.0):v1(a),v2(b){}
	void msg();
	friend ostream & operator<<(ostream& os,const Bad_heam& bh);


};

inline
void Bad_heam::msg(){
	cout << "ERROR:: hmen( " <<v1 <<"," <<v2 <<"):invalid arguments:a = -b\n"; 
}

class Bad_gmean{
	private:
	double v1;
	double v2;
	public:
	Bad_gmean(double a=0.0,double b=0.0):v1(a),v2(b){}
	const char *msg();

};

inline
const char *Bad_gmean::msg(){
	return "gmean() arguments should be  >= 0";

}

ostream & operator<<(ostream& os,const Bad_heam& bh){
	os <<  "ERROR:: hmen( " <<bh.v1 <<"," <<bh.v2 <<"):invalid arguments:a = -b [-> in function opetator << ostream]\n"; 
	return os;
}



#endif