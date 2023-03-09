#include<iostream>
#include<cstdlib>
using namespace std;

/*异常
调和平均数 10 和 -10 
在函数里面抛出错误 错误类型可以是字符串,数字，或者类对象
然后在运行的时候 try{ 这个函数}
最后 catch(const char *s){怎样处理，比如 continue;}
*/

template<class T>
T hmean(T t1,T t2);

int main(){
	double x,y,z;
	cout <<"Enter two number:";
	while((cin >> x >>y)){

		try{ 
			z=hmean(x,y); //当 x==-y的时候,函数会停止运行，然后抛出一串字符串 ，被catch 捕获，然后再处理
		}

		
		catch(const char*s){ //catch 表明这是一个处理程序 函数里面throw 会被赋值给s
			cout << s << endl;
			cout << "Enter new pair of argments:";
			continue;
		}
		

		cout <<  x << " and " << y << " Harmonic mean is " << z << " \n";
	

		cout <<"Enter two number:";
	}
	return 0;
} 

template<class T>
T hmean(T t1,T t2){
	if(t1==-t2)
		throw "bad function hman() arguments, a ==-b not allowed"; //终止函数的执行,抛错

	return (2.0*t1*t2) / (t1+t2);
}