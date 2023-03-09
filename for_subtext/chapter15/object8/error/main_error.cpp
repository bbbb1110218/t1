#include<iostream>
#include<cstdlib>
#include "exe_mean.h"
#include <cmath>
using namespace std;


double hmean(double t1,double t2);
double gmean(double a,double b);

int main(){
	double x,y,z;
	
	cout <<"Enter two number:";
	while((cin >> x >>y)){

		try{ 
			z=hmean(x,y); 
			cout <<  x << " and " << y << " Harmonic mean is " << z << " \n";
			z=gmean(x,y);
			cout <<  x << " and " << y << " g mean  result  is " << z << " \n";
		}

		//第一个异常
		catch(Bad_heam &b){  		//类要用引用
			b.msg();  				//调用类方法
		
			cout <<"Enter two number again :";
			continue;
		}

		//第二个异常
		catch(Bad_gmean & g){
			cout <<g.msg() << endl;  //调用类的方法 返回字符串
			cout <<"Enter two number again :";
			continue;

		}

		cout <<"Enter two number:";
	}
	
	return 0;
} 

double hmean(double t1,double t2){
	if(t1==-t2)
		throw Bad_heam(t1,t2);  //抛出错误 错误类型是  类的对象

	return (2.0*t1*t2) / (t1+t2);
}

double gmean(double a,double b){
	if(a <0 || b< 0){
		throw Bad_gmean(a,b);
	}
	return sqrt(a*b);
}