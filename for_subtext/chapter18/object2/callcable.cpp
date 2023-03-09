#include <iostream>
using namespace std;

template <typename T,typename F>
T use_f(T v,F f){
	static int  count =0;
	count++;
	cout <<  "Use_f count :" << count << " , Addr = " << &count << endl;
	return f(v);
}

class Fp{
private:
	double z_;
public:
	Fp(double z=1.0):z_(z){}
	double operator()(double p){
		return z_ * p;
	}
};

class Fq{
	private:
		double z_;
	public:
	Fq(double z=1.0):z_(z){}
	double operator()(double q){
		return z_ + q;
	}
};


double dub(double x){return 2.0 *x;};
double square(double x){return x*x;};

//特征标 参数为 double 返回值也是double 
//头文件 <functional>



int main(){
	double y=1.21;


	//type Fuction double (*)(double)
	// use_f<double,double(*)(double)>(y,dub);

	cout << use_f(y,dub) << endl;
	cout << use_f(y,square) << endl;

	Fq fuck(220.2);

	cout << use_f<double,Fq >(y,fuck) << endl;
	cout << use_f<double,Fp >(y,Fp(3.2)) << endl;

	//lambda 表达式 
	//lambda 为单独的数据类型，不和其他

	auto l1=[](double x){return  x+0.1;};
	auto l2=[](double x){return  x+0.1;};

	cout << use_f(y,l1) << endl;
	cout << use_f(y,l2) << endl;



	return 0;
}