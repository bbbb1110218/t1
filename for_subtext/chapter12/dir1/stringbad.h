#ifndef __STRING_BAD_H__
#define __STRING_BAD_H__

#include <iostream>

using namespace std;


class StringBad{
private:
	char *str;				//字符串的地址;
	int len;				//字符串的长度
	static int num_strings;	//静态int，无论创建多少个对象，都共用一个静态变量
							//不属于任何类的对象，独立于所有的类的对象
							//对所有类的对象都是可见的
public:
	StringBad();
	StringBad(const char*s);
	~StringBad();	//析构函数，没有参数没有返回值

	friend ostream& operator<<(ostream&os,const StringBad &st);
};



#endif