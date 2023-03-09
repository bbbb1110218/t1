#include<string>
#include<iostream>
using namespace std;


template<class T,T val>
bool fuck(T n){
	return val >n;
}





int main(){

	int val=static_cast<int>([](int n){return n});
	cout << val << endl; ;
	
	return 0;
}