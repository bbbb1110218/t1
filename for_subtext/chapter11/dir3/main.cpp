#include <iostream>
#include "time.h"

using namespace std;


int main(){
	Time t1(2,30);
	cout <<t1;
	t1.show();
	Time t2=2.5 *t1;
	t2.show();
	Time t3=t1 *10.0;
	t3.show();

	cout << "t1:" << t1 
	<<"t2:" <<t2 
	<<"t3:" <<t3;

	int a=2;
	int b=a<<2;
	cout<<b;


	
	return 0;

}