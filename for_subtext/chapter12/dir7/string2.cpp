#include "string2.h"
#include <cstring>

int String::num_strings=0;


String::String(){
	len=0;
	str=new char[0];
	str[0]='\0';
	num_strings++;
}

String::~String(){

	num_strings--;
	delete []str;
	cout <<"Num_strings:" << num_strings << endl;
}

String::String(const char *st){
	len=strlen(st);
	str=new char[len+1];
	strcpy(str,st);
	num_strings++;
}

String::String(const String&s){
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	num_strings++;
}

String& String::operator=(const String& s){
	if(this == &s)
		return *this;
	delete []str;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	return *this;
}


ostream& operator<<(ostream&os,const String& s){
	os << s.str;
	return os;

}

istream& operator>>(istream &is,String& s){
	char temp[100];
	is.getline(temp,100);
	s.len=strlen(temp);
	delete []s.str;
	s.str=new char[s.len+1];
	strcpy(s.str,temp);
	s.str[s.len]='\0';
	return is;
}

String operator+(const char* st,const String& s){
	String temp;
	temp.len=strlen(st)+s.len;
	temp.str=new char[temp.len+1];
	strcpy(temp.str,st);
	strcat(temp.str,s.str);
	return temp;
}

String String::operator+(const String&s){
	String temp;
	temp.len=len +s.len;
	temp.str=new char[temp.len+1];
	strcpy(temp.str,str);
	strcat(temp.str,s.str);
	return temp;
}

void String::stringup(){
	for(int i=0;str[i] !='\0';i++){
		str[i]=toupper(str[i]);
	}
}

void String::stringlow(){
	for(int i=0;str[i] !='\0';i++){
		str[i]=tolower(str[i]);
	}
}


int String::has(char ch)const {
	int n=0;
	for(int i=0;str[i]!='\0';i++){
		if(str[i] ==ch)
			n++;
	}
	return n;
}

String& String::operator=(const char* st){
	delete []str;
	len=strlen(st);
	str=new char[len+1];
	strcpy(str,st);
	return *this;
}

bool String::operator==(const String &s){
	if(len !=s.len)
		return false;
	for(int i=0;i<len;i++){
		if(str[i] !=s.str[i])
			return false;
	}
	return true;
}







