

#include <iostream>
#include <cstring>

using namespace std;

class Frabjous{
private:
	char fab[20];
public:
	Frabjous(const char *s="c++"){strncpy(fab,s,20);}
	virtual void tell(){cout << fab;}
};

class Gloam:private Frabjous{
private:
	int glip;
	
public:
	Gloam(int g=0,const char *s="c++");
	Gloam(int g,const Frabjous&f);
	void tell();
};


Gloam::Gloam(int g,const char *s):glip(g),Frabjous(s){
}



Gloam::Gloam(int g,const Frabjous &f):glip(g),Frabjous(f){	
}

void Gloam::tell(){
	Frabjous::tell();
	cout << endl;
	cout << glip << endl;
}


int main(){
	Gloam t1(10,"hello");
	Frabjous t2("fuckyou");
	Frabjous *pt=&t2;
	pt->tell();
	cout << endl;


	return 0;


	
}