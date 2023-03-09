#include "stringbad.h"
#include <cstring>

int StringBad::num_strings=0;

StringBad::StringBad(){
	len=4;
	str=new char[len+1];
	strcpy(str,"None");
	//num_strings++;
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" ]" << endl;

}

StringBad::~StringBad(){

	std::cout <<"[" << str << "be Delete, num_strings = "<< --num_strings <<" ]" << endl;
	delete []str;
	
}

StringBad::StringBad(const char *st){
	len=strlen(st);
	str=new char[len+1];
	strcpy(str,st);
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" ]" << endl;
}


StringBad::StringBad(const StringBad& s){
	len=s.len;
	strcpy(str,s.str);
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" in copy func]" << endl;

}

StringBad& StringBad::operator=(const StringBad& s){
	delete []str;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	std::cout << "[" << str <<" be Created , num_strings = "<< ++num_strings <<" in func ==]" << endl;
	return *this;
}


ostream& operator<<(ostream &os,const StringBad&s){
	os << "[" << s.str <<" be Print ]" << endl;
	return os;
}
