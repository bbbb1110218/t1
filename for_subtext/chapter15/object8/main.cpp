#include<iostream>
#include<cstdlib>
using namespace std;

/*异常
调和平均数 10 和 -10 
使用abort 终止的意思
*/

template<class T>
T hmean(T t1,T t2);

int main(){
	double x,y,z;
	cout <<"Enter two number:";
	while((cin >> x >>y)){
		z=hmean(x,y);
		cout <<  x << " and " << y << " Harmonic mean is " << z << " \n";
		cout <<"Enter two number:";
	}
	return 0;
} 

template<class T>
T hmean(T t1,T t2){
	if(t1==-t2)
	{
		cout <<"invalid arguments to heman()" << endl;
		abort();  //头文件 cstdlib中
					//运行中出现的错误
	}
	return (2.0*t1*t2) / (t1+t2);
}