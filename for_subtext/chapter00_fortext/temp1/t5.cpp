// template <class T>    #1 函数通用模版
// void Swap(T &,T&);

// template<>void Swap<job><job &,job &>; #2 显示具体化

#include <iostream>
using namespace std;

namespace ss{
	
template<class T>
void Swap(T& t1,T &t2);

template void Swap<char>(char&,char&); //


}



int main(void){

	using namespace ss;

	int a=4,b=5;
	Swap(a,b);
	cout<< a <<"\t " << b << endl;

	char c='c',d='d';
	Swap(c,d);

	cout << c << "\t" << d << endl;

	return 0;
}



namespace ss { 

template<class T>
void Swap(T& t1,T &t2){
	T temp=t1;
	t1=t2;
	t2=temp;
}

}