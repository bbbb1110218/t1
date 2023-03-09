#include <iostream>
#include "brassabc.h"


int main(){

	Brass minliang("minliang",1234567,22);


	BrassPlus minrui("minrui");
	minrui.withdraw(300);
	minrui.show();
	minrui.save(100);
	minrui.show();
	minrui.save(100);
	for(int i=0;i<5;i++){
		minrui.save(i*10.0);
	}


	
	


	return 0;
}