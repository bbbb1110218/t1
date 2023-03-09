#include <iostream>
using namespace std;

class Tv; //前置声明 TV类

class Remote{
public:
	void getvalue(Tv &t);  //在此之前不认识TV 需要前置声明 TV;

	void sayhellokitty(){		//其他方法
		cout <<"hello,kitty" << endl;
	}
	void show(Tv &t);

	void reset(Tv&t,int n); //因为要修改Tv中的私有变量，但是前置声明之声明了有这么一个类，
							//但是还不知道类中有哪些私有变量，所以这个函数需要写在类声明后面
							//可以用inline 声明为内联函数，也可以不用
};


class Tv{
private:
	int channel;
public:
	Tv(int c=0):channel(c){}
	int value(){return channel;}
	void show() {cout <<"i am in class_Tv method_show()" << endl;}
	
	friend void Remote::getvalue(Tv&t);  //声明 Remote中的getvalue为友元函数
	friend void Remote::reset(Tv&t,int n); //修改私有变量
};


inline  //inline 用不用都行
void Remote::getvalue(Tv&t){   //方法中channel为私有变量，如果定义在类中不认识
	cout <<"value:" << t.channel << endl;
}

void Remote::show(Tv &t){
	t.show();
}

void Remote::reset(Tv&t,int n){
	t.channel =n;
}


int main(){
	Tv tv(6);
	Remote rem;
	rem.getvalue(tv);
	rem.sayhellokitty();
	rem.show(tv);
	rem.reset(tv,666); //tv中的私有变量
	cout << tv.value() << endl;
	return 0;
}



