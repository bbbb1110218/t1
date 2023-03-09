#include <iostream>
#include "myhead.h"
using namespace std;





int main(){
	
	Num N[5];
	for(int i=0;i<5;i++){
		N[i]=Num(i+i);
	};

	Num a;
	for(int i=0;i<5;i++){
		a =a+N[i];
	};
	a.show();

	return 0;
};


