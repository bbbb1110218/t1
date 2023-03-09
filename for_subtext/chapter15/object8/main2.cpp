#include<iostream>
#include<cstdlib>
using namespace std;

/*异常
调和平均数 10 和 -10 
使用abort 终止的意思
*/

template<class T>
bool hmean(T t1,T t2,T* ans);

int main(){
	double x,y;
	double *z;
	z=new double;
	cout <<"Enter two number:";
	while((cin >> x >>y)){

		if(hmean(x,y,z)){
			cout <<  x << " and " << y << " Harmonic mean is " << *z << " \n";
		}else{
			cout <<"error in main\n";
		}


		cout <<"Enter next set of number:";
		
		
		
	}
	delete z;
	return 0;
} 

template<class T>
bool hmean(T t1,T t2,T* ans){
	if(t1==-t2)
	{
		cout <<"invalid arguments to heman()" << endl;
		return false;
	}
	*ans= (2.0*t1*t2) / (t1+t2);
	return true;
}