#include <iostream>
#include <cstring>
using namespace std;


class Temp{
private:
	char *name;
	int size;
public:
	Temp(){name=nullptr;size=0;}
	Temp(const char* s);
	~Temp(){cout <<name <<"be deleted\n";delete []name;}
	Temp(const Temp&t);
	void show(){cout <<"i am in show and my name is " << name << endl;};
	Temp & operator=(const Temp&t);
};


int main(){
	Temp n1("minliang");
	n1.show();
	Temp n2(n1);
	n2.show();
	Temp * pn3=new Temp("minrui");
	pn3->show();

	delete pn3;


	return 0;
}



Temp::Temp(const char* s){
	size=strlen(s);
	name =new char[size+1];
	strcpy(name,s);
}


Temp::Temp(const Temp&t){
	size=t.size;
	name= new char[size+1];
	strcpy(name,t.name);
}

Temp& Temp::operator=(const Temp &t){
	if(this ==&t)
		return *this;
	delete []name;
	size=t.size;
	name= new char[size+1];
	strcpy(name,t.name);
	return *this;
}