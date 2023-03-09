#include <iostream>

using namespace std;



template<typename T>
const T & compair(T &a,T &b);



int main(){
	int a=5;
	int b=7;
	int c;
	c=compair(a,b);
	c=9;
	cout <<c << endl;
	return 0;

}

template<typename T>
const T &compair(T &a,T &b){
	return a >b? a:b;
}