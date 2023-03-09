#include <iostream>
#include "head.h"


template<class T>
void Swap(T&t1,T&t2){
	using namespace std;
	cout <<" i am in oother file" << endl;
	T temp=t1;
	t1=t2;
	t2=temp;


}