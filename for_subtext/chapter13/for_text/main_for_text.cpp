#include <iostream>
using namespace std;

template<typename T>
void swap(T *,T *);

int main(){
	double a=6;
	double b(0);
	swap(a,b);
	cout <<a << " " << b << endl;
	return 0;
}


template<typename T>
void swap(T *t1,T *t2){
	T temp=*t1;
	*t1=*t2;
	*t2=temp;

}