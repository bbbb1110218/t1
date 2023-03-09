#include "stringg.h"
#include <cstring>

int String::num_strings=0;

String::String(){
	len=4;
	str=new char[len+1];
	strcpy(str,"None");
	//num_strings++;
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" ]" << endl;

}

String::~String(){

	std::cout <<"[" << str << "be Delete, num_strings = "<< --num_strings <<" ]" << endl;
	delete []str;
	
}

String::String(const char *st){
	len=strlen(st);
	str=new char[len+1];
	strcpy(str,st);
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" ]" << endl;
}


String::String(const String& s){
	len=s.len;
	strcpy(str,s.str);
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" in copy func]" << endl;

}

String& String::operator=(const String& s){
	delete []str;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" in func ==]" << endl;
	return *this;
}


ostream& operator<<(ostream &os,const String&s){
	os << "[" << s.str <<" be Print ]" << endl;
	return os;
}
