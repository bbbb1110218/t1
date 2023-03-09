#include "stringbad.h"
#include <cstring>


int StringBad::num_strings=0;   //不放在头文件中，避免多次被赋值修改引发错误
								//初始化类里面的静态变量
								//什么描述如何分配内存，但是并不分配内存
								//单独存储，不是类的组成部分
								//不使用关键字 static


StringBad::StringBad(const char *s){   //StringBad("hello,kitty");
	len=strlen(s);
	str=new char[len + 1 ]; //开辟内存空间
	strcpy(str,s);
	int i;
	num_strings++;//静态变量++，统计创建了多少个变量
	cout <<num_strings <<" :"<< num_strings <<": \""<<str <<"\" be Created" << endl;

}


StringBad::StringBad(){
	len =4;
	str=new char[4];
	str[len-1]='\0';
	strcpy(str,"C++");
	num_strings++;
	cout << num_strings <<": \""<<str <<"\" be Created" << endl;
}

StringBad::~StringBad(){
	cout <<"\"" << str <<"\" be Delete" << endl;
	delete []str;  					//构造函数开辟的内存空间，析构函数删除
	num_strings--;
	cout << num_strings <<" left.\n";

} 

ostream& operator<<(ostream &os,const StringBad&st){
	os << st.str ;
	return os;
}
