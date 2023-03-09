#ifndef __STRING_BAD_H__
#define __STRING_BAD_H__
#include <iostream>
using namespace std;


class StringBad{
private:
	char *str;
	int len;
	static int num_strings;
public:
	StringBad();
	~StringBad();
	StringBad(const char *st);
	StringBad(const StringBad& s);
	StringBad& operator=(const StringBad& s);
	friend ostream& operator<<(ostream &os,const StringBad&s);

};

#endif