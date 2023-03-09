#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
using namespace std;


class String{
private:
	char *str;
	int len;
	static int num_strings;
public:
	String();
	~String();
	String(const char *st);
	String(const String& s);
	String& operator=(const String& s);
	friend ostream& operator<<(ostream &os,const String&s);

};

#endif