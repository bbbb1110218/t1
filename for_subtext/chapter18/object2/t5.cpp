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
	vector<int> numbers(SIZE1*10000);
	srand(time(0));
	generate(numbers.begin(),numbers.end(),rand); //rand()产生的随机数一次放在迭代器里面

	

	//对于接受函数指针和函数符的函数 可以使用lambda 表达式
	//lambda 没有声明返回值 编译器  decltype 自动推断
	//lambda 没有函数名
	//给lambda 表达式 加上函数名字 auto 编译器推断

	int count3,count13;
	count3=count13=0;


	count3=count_if(numbers.begin(),numbers.end(),[](int n){return n %3 ==0;});

	cout << "Lambda expression value = " << count3 << endl;

	for_each(numbers.begin(),numbers.end(),[&count13](int n){count13 += (n %13 ==0);});

	cout << "Lambda count13 value = " << count13  << endl;


	//lambda 额外的功能
	//可以访问作用域内的任何动态变量 捕获的的值放在[]内  加上& 是按照引用访问变量
	// [&] 的功能 

	count3=count13=0;

	for_each(numbers.begin(),numbers.end(),[&](int a){count3 += (a %3==0);count13 +=(a %13==0);});
											//lambda 里面的变量全都为引用
	cout << "count3 =" << count3 << endl;
	cout << "count13 = " << count13 << endl;





	return 0;


}