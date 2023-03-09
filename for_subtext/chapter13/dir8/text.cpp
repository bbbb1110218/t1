#include "text.h"
#include <cstring>




BaseABC::BaseABC(const char *name,int age){
	name_=new char[strlen(name)+1];
	strcpy(name_,name);
	age_=age;
}


BaseABC::BaseABC(const BaseABC&ba){
	name_=new char[strlen(ba.name_)+1];
	strcpy(name_,ba.name_);
	age_=ba.age_;
}

BaseABC::~BaseABC(){
	delete []name_;
}

BaseABC& BaseABC::operator=(const BaseABC& ot){
	if(this ==&ot)
		return *this;
	delete []name_;
	name_=new char[strlen(ot.name_)+1];
	strcpy(name_,ot.name_);
	age_=ot.age_;
	return *this;
}

ostream& operator<<(ostream &os,const BaseABC& ba){
	cout <<"\n";
	os << "姓名 : "<<ba.name_ << "\n";
	os << "年龄 : "<<ba.age_ << "\n";
	return os;
}


void BaseABC::show(){					//⚠️:基类的的虚方法：调用非虚函数
	cout << *this;
}

Person::Person(const char *name,int age, const char *hobby,
	double height,double weight):BaseABC(name,age),
		height_(height),weight_(weight)
{

	hobby_ = new char[strlen(hobby) +1];
	strcpy(hobby_,hobby);
	
}

Person::Person(const BaseABC& ba,const char * hobby,double height,
	double weight):BaseABC(ba),					//⚠️ 重点1: 派生类构造 还是要用基类的构造方法
	height_(height),weight_(weight)
{
	hobby_ = new char[strlen(hobby) +1];
	strcpy(hobby_,hobby);

}

Person::Person(const Person &pe):BaseABC(pe){	//⚠️ 重点2:还是要用基类初始化 构造方法

	hobby_=new char[strlen(pe.hobby_) +1];
	strcpy(hobby_,pe.hobby_);
	weight_=pe.weight_;
	height_=pe.height_;
}

Person::~Person(){

	delete []hobby_;	//删除
}

Person& Person::operator=(const Person& pe){
	if(this ==&pe)
		return *this;
	BaseABC::operator=(pe);						//⚠️ 重点3:在派生类里面 用父类的赋值运算符 *this指针 可以省略
												//这是赋值运算符的 函数表示方法 指明用父类的  = 赋值运算符  类似 a=2 的语法
												//如果不用函数表示法：派生类会用自己的 = 赋值运算符，会造成无限递归
	delete []hobby_;
	hobby_ = new char[strlen(pe.hobby_)+1];
	height_ = pe.height_;
	weight_ = pe.weight_;
	return *this;
}

ostream& operator<<(ostream&os,const Person&pe){   //⚠️ 重点4: 非成员函数，不能当作虚函数来使
	os << (const BaseABC &) pe ;					//⚠️ 重点5:转换类型 在打印 os根据数据类型 使用哪种方法
	os << "姓名 : "<< pe.hobby_ << "\n";
	os << "身高 : "<< pe.height_ << "\n";
	os << "体重 : "<< pe.weight_ << "\n";
	return os;
}

void Person::show(){				//⚠️ 重点6:当作虚函数了,使用非成员函数来操作自己
									//⚠️
	cout <<*this;
}









