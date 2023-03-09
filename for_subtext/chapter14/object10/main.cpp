#include <iostream>
#include "stack.h"

using namespace std;





template<template<class T> class Thing>  //类的模版
class Crab{
private:
	Thing<int> s1; //模版类
	Thing<double> s2; //类2
public:
	bool push(int a,double x){return s1.push(a) && s2.push(x);}
	bool pop(int &a,double &x){return s1.pop(a) && s2.pop(x);}
	void show()const{
		s1.show();
		s2.show();
	}
};



int main(){
	int ni; 

	double nb;

	Crab<Stack> nebula;
	cout <<"enter int & double pairs such as (5 5.6), 0,0 to end" << endl;

	while((cin >> ni >> nb) && (ni>0 || nb>0) ){
		if(!nebula.push(ni,nb))
			break;
		cout <<"入栈 " << "int : " << ni <<" ,double : " << nb << endl;
	}

	nebula.show();

	while(nebula.pop(ni,nb))
		cout <<"出栈 " << "int : " << ni <<" ,double : " << nb << endl;




	return 0;
}