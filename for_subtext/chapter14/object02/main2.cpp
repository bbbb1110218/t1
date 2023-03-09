#include "student2.h"


int main(){

	Student s1("minliang",4);
	cout <<s1.Name() << endl;
	s1[0]=55.5;
	s1[2]=44.4;
	cout <<s1 ;


	return 0;
}