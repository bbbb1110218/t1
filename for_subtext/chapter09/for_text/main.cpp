#include <iostream>
#include "head.h"

using namespace std;

// extern template void Swap(char * &, char* &);
// extern template void Swap(int *&,int *&);

// template<>
// void Swap<int *>(int *& a,int *&b){
// 	cout << *a << *b << endl;
// }

// template<class T>
// void Swap(T&t1,T&t2){
// 	cout <<"hello,kitty"<< endl;
// }

//template void Swap(int *&,int *&);


int main(){
	int a=6,b=7;
	int *pa=&a;
	int *pb=&b;

	Swap(a,b);

	return 0;

}