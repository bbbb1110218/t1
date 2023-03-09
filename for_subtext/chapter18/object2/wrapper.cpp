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

								//定义包装器
	function<double(double)> fdd=dub;  //包装器指向 dub 函数  // 函数参数和返回值都是double
	cout << use_f(y,fdd) << endl;
	

	fdd=square;	//指向第二个函数
	cout << use_f(y,fdd) << endl;

	fdd=Fp(2.0); //指向第三个 第三个为仿函数
	cout << use_f(y,fdd) << endl;

	fdd=Fp(23.0); //指向第四个 第四个为仿函数
	cout << use_f(y,Fp(3.2)) << endl;

	
	fdd=[](double x){return  x+0.1;};	//指向第一个lambda 函数

	cout << use_f(y,fdd) << endl;

	fdd=[](double x){return  x+x/2;}; //指向第二个lambda 函数

	cout << use_f(y,fdd) << endl;
	

	return 0;
}