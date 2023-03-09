#include "myhead.h"
using namespace std;


Num::Num(int argn){
	n=argn;

}

void Num::show(){
	cout <<"Num(n= "<<n<<");"<< endl;

}

Num& Num::operator+=(int argn){
	n +=argn;

	return *this;
}

Num& Num::operator+(const Num& N2){
	n +=N2.n;
	return *this;
}

Num::~Num(){
	cout <<"Delete : n="<<n<< endl;
}

