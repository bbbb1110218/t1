#include <string>
#include <iostream>
#include <memory>


#define __USE__ if(1){{ 
#define __UNUSE__ if(0){{ 
#define __END__ }}


using namespace std;

int main(){

__UNUSE__ //没用的
	auto_ptr<string> films[5]={
		auto_ptr<string>(new string("黑客帝国1")),  //一定要加new a
		auto_ptr<string>(new string("黑客帝国2")),
		auto_ptr<string>(new string("黑客帝国3")),
		auto_ptr<string>(new string("黑客帝国4")),
		auto_ptr<string>(new string("黑客帝国5"))
	};

	auto_ptr<string> pwin;
	pwin=films[2];		 //film2 丢失了指针所有权利,可以可以理解为空指针
	cout << *pwin << endl;

	for(int i=0;i <5;i++){
		cout << *films[i] << endl;  //循环到film[2]的时候 会出现段错误
	}
__END__



__UNUSE__ //有用的
		shared_ptr<string> films[5]={
			shared_ptr<string>(new string("黑客帝国1")),  //一定要加new a
			shared_ptr<string>(new string("黑客帝国2")),
			shared_ptr<string>(new string("黑客帝国3")),
			shared_ptr<string>(new string("黑客帝国4")),
			shared_ptr<string>(new string("黑客帝国5"))
									};

	shared_ptr<string> pwin;
	pwin=films[2];		//计数器初始值为0，创建一个对象 计数器+1  析构函数 if(计数器==1) delete ;计数器--
	cout << *pwin << endl;

	for(int i=0;i <5;i++){
		cout << *films[i] << endl;  //循环到film[2]的时候 会出现段错误
	}

	
__END__

__USE__
	unique_ptr<string> films[5]={
			unique_ptr<string>(new string("黑客帝国1")),  //一定要加new a
			unique_ptr<string>(new string("黑客帝国2")),
			unique_ptr<string>(new string("黑客帝国3")),
			unique_ptr<string>(new string("黑客帝国4")),
			unique_ptr<string>(new string("黑客帝国5"))
									};

	// unique_ptr<string> pwin;
	// pwin=films[2];		
	// cout << *pwin << endl;

	for(int i=0;i <5;i++){
		cout << *films[i] << endl;  //循环到film[2]的时候 会出现段错误
	}


__END__

__UNUSE__
	
	//auto_prt的用法:当p2 指向p1所指向的内存空间 p1的所有全被剥夺,不能使用
	//编译不回报错，运行的时候才报错
	auto_ptr<string> p1(new string("hello1"));
	autp_ptr<string> p2;
	p2=p1;

	//unique_ptr:计数器的初始值为0 每创建一个对象都会计数器+1
	//复制运算符里面  if 计数器 >1 throw() 直接报错 
	//编译直接报错，不会运行
	unique_ptr<string> p1(new string("hello1"));
	unique_ptr<string> p2;
	p2=p1;

	//shared_ptr:计数器的初始值为0 每创建一个对象都会计数器+1
	//析构函数里面 if 计数器==1 delete ；计数器 --
	shared_ptr<string> p1(new string("hello1"));
	shared_ptr<string> p2;
	p2=p1;



__END__



return 0;
}