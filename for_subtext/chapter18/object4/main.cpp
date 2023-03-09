#include <iostream>
using namespace std;

/*
... 元运算符

template <typename... Args> 	//Args匹配多种数据类型
void show_list(Args... args){	//函数参数包
	
}
*/

template<class T>
void show(T & t){
	cout << t << endl;
}

template<typename...Args>
void show(Args...args){
	show(args);
}

int main()
{

	show(1,3,3.4);


	return 0;
}