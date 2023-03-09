#include<valarray>
#include<initializer_list>

#include <iostream>

using namespace std;


template<class T>
T sum(initializer_list<T> li){
	T value=0;
	for(auto p=li.begin();p!=li.end();p++)
		value +=*p;
	return value;
}

template<class T>
T average(initializer_list<T> li){
	return sum<T>(li)/(li.end() -li.begin());
	//显示调用 sum<T> 求和 除以 (迭代器尾减掉 迭代器头) 等于个数
}


int main(){
	initializer_list<double> b{4,4,8.6,0};
	cout << sum(b) << endl;
	cout << average(b) << endl;

	cout << average({3,4,5,6,8}) << endl;
	//隐式转换成 initializer_list<int>

	cout << average(initializer_list<double>{3.0,4,5,6,8}) << endl;
	//不知道参数为甚么类型，需要显示  3.0 与 int 类型






	return 0;
}