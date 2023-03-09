#include<iostream>
#include<cstdlib>
#include "exe_mean.h"
#include <cmath>
using namespace std;


double hmean(double t1,double t2);
double gmean(double a,double b);
double mean(double a,double b);

int main(){
	double x,y,z;
	
	cout <<"Enter two number:";
	while((cin >> x >>y)){

		try{ 
			z=mean(x,y); 
			cout <<  x << " and " << y << " mean is " << z << " \n";
		}

		
		//第一个异常
		catch(Bad_heam &b){  		//类要用引用
			b.msg();  				//调用类方法
			cout << "2)exception " << endl;
			cout <<"Enter two number again :";
			continue;
		}

		//第二个异常
		catch(Bad_gmean  &g){
			cout <<g.msg() << endl;  //调用类的方法 返回字符串
			cout <<"Sorry Quit now"<< endl;
			break;

		}

		catch(const char *s){
			cout <<s << endl;
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

double mean(double a,double b){
	double am,hm,gm;
	am =(a+b)/2;
	try{
		hm =hmean(a,b);
		gm=gmean(a,b);
	}

	catch(Bad_heam  &bh){
		bh.msg();
		cout << "1)exception " << endl;//只处理 第一个异常
		throw ;   //会接着把 Bad_heam & bh 这个异常再次抛出
				   //下面的代码不会执行
	}
	cout <<"hello,kitty" << endl;

	return (am+hm+gm)/3.0;

}

