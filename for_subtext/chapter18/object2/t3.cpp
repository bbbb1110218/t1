#include <iostream>

using namespace std;

class Action
{	int a;
	public:
		Action(int i=0):a(i){}
		int val()const {return a;}
		virtual void f(char ch)const final{cout << val() << " " << ch <<  endl;}
									//final 禁止派生类 重写该函数 写在const 后面
};

class Bingo:public Action{
public:
	Bingo(int i=0):Action(i){}
	void f(char ch)const override{cout << val() << " " << ch << "!!!!"<< endl;}
	
		//override 明确的表明，强制的告诉编译器，和看代码的其他用户 这是派生类的重载  需要写在const 后面

};

int main(){
	Bingo b(10);
	//b.f('@'); //基类的  可以显式的使用 b.Action::f('@');
	b.f('a');


	return 0;
}