#include <iostream>

using namespace std;


template<class T1,class T2>
class A{
public:
	void show();
};


template<class T1,class T2>
void A<T1,T2>::show(){
	cout <<"Use general definition|通用的模版定义" <<endl;
}


template<typename T>
T copy(const T& t);


int main(){
	//double a=6.01;
	cout << copy(6.01f) << endl;

	return 0;
}


template<class T>
T copy( const T& t){
	return t+t;
}


