#include "stringbad.h"



void show1(StringBad &rsb);
void show2(StringBad sb);  //编译器会拷贝类，不是使用默认的构造函数,但是会使用析构函数
							//从类拷贝类，StringBad(const StringBad& copy);

int main(){

	StringBad headline1("hello.kitty");
	StringBad headline2("Good morning");
	StringBad headline3("I love you,rick");
	cout <<headline1 << endl;
	cout <<headline2 << endl;
	cout <<headline3 << endl;
	show1(headline2);
	show2(headline2); //编译器会拷贝类，不是使用默认的构造函数,但是会使用析构函数
					  //从类拷贝类，StringBad(const StringBad& copy); 解决办法
	
	return 0;
}

void show1(StringBad &rsb){
	cout <<"by re引用:" << rsb <<endl;
}

void show2(StringBad sb){
	cout <<"by 不引用:" << sb <<endl;
}