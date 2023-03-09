#include <iostream>
using namespace std;


void sum_value(){
	return 0.0;
}

template<class T>
void sum_value(T t){
	return t;
}


template<class T,class... Args>
long double sum_value(T value,Args... args){
	value +=sum_value(args...);
	return value;

}


int main(){
	
	cout << sum_value(111,2,5.5) << endl;
	cout << sum_value('a','b',5.,6) << endl;
	return 0;

}

