#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

/*
*/

using namespace std;

const int SIZE1=39;

bool f3(int it){
	return it %3 ==0;
}

bool f13(int it){return it % 13==0;}


class f_mode{
private:
	int value;
public:
	f_mode(int n):value(n){}
	bool operator()(int input){
		return input % value==0;
	}
};




int main(){
	vector<int> numbers(SIZE1);
	srand(time(0));
	generate(numbers.begin(),numbers.end(),rand); //rand()产生的随机数一次放在迭代器里面
	int size=count_if(numbers.begin(),numbers.end(),f3);
	int size2=count_if(numbers.begin(),numbers.end(),f13);

	cout << "count of numbers Divisible by 3 : "<<size << endl;
	cout << "count of numbers Divisible by 13 : "<<size2 << endl;

	numbers.resize(3900);
	generate(numbers.begin(),numbers.end(),rand);


	size=count_if(numbers.begin(),numbers.end(),f_mode(3));  
													//函数符号 需要加上() 隐式 实例话 类
	cout << "count of numbers Divisible by 3 : "<<size << endl;

	size2=count_if(numbers.begin(),numbers.end(),f_mode(113));

	cout << "count of numbers Divisible by 11 : "<<size2 << endl;

	

	//对于接受函数指针和函数符的函数 可以使用lambda 表达式
	//lambda 没有声明返回值 编译器  decltype 自动推断
	//lambda 没有函数名
	//给lambda 表达式 加上函数名字 auto 编译器推断


	auto f13=[](int n){return n%13==0;};

	size=count_if(numbers.begin(),numbers.end(),[](int n){return n %3 ==0;});

	cout << "Lambda expression value = " << size << endl;

	size=count_if(numbers.begin(),numbers.end(),[](int n){return n %113 ==0;});

	cout << "Lambda expression value = " << size << endl;

	size=count_if(numbers.begin(),numbers.end(),f13);
	cout << "Lambda expression value = " << size << endl;


	//lambda 额外的功能
	//可以访问作用域内的任何动态变量 捕获的的值放在[]内  加上& 是按照引用访问变量
	




	








	return 0;


}