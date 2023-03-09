#include <iostream>
using namespace std;
#include "classic.h"

void Bravo(const Cd & disk);

int main(){

	Cd c1("Beatles","capitol",14,35.5);
	Classic c2=Classic("Piano Sonata in B flat,Fantasia in C",
						"Alfred Brendel","Philips",2,57.17);
	Cd *pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout <<"Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd =&c2;
	pcd->Report();

	cout <<"calling a function With a cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assigument:";
	Classic copy;
	copy=c2;
	copy.Report();
	cout <<sizeof c1 <<endl;
	cout <<sizeof c2 <<endl;

	return 0;
}



void Bravo(const Cd & disk){
	disk.Report();
}