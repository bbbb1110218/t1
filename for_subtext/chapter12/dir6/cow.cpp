#include <iostream>
#include <cstring>
using namespace std;

class Cow{
private:
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();			//默认构造函数
	Cow(const char *nm,const char *ho,double w);
	Cow(const Cow &c );		//复制构造函数 左边必须是类定义 赋值给新类
	Cow(const char * nm);

	~Cow();  //析构函数 用[]开辟出来的内存，必须要用[]delete
	Cow &operator=(const Cow&c);  //赋值运算符，两边都是类的


	Cow &operator=(const char *nm);

	void ShowCow()const;

};

int main(){
	Cow c1;
	Cow c2;
	c2=c1;
	c2.ShowCow();
	c2="minliang";
	c2.ShowCow();


	return 0;
}

Cow::Cow(){
	cout <<"[在默认默认构造函数内]" << endl;
	strcpy(name,"NO Name");

	hobby=new char[9];
	strcpy(hobby,"No hobby");
	weight=0.0;
}

Cow::Cow(const char * nm){
	cout <<"[在单个参数构造函数内]" << endl;
	strcpy(name,nm);
	hobby=new char[9];
	strcpy(hobby,"No hobby");
	weight=0.0;
}

Cow::Cow(const char *nm,const char *ho,double w){
	cout <<"[在多参数构造函数内]" << endl;
	strncpy(name,nm,19);
	name[19]='\0';
	hobby=new char[strlen(ho)+1];
	strcpy(hobby,ho);
	weight=w;
}

Cow::Cow(const Cow &c){
	cout <<"[在复制构造函数内]" << endl;
	strcpy(name,c.name);
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight=c.weight;
}

Cow::~Cow(){
	//cout <<"Addr" << (char*)this << "will be delete\n";
	delete []hobby;  //用[]开辟出来的内存，必须要用[]delete
}
Cow &Cow::operator=(const Cow&c){
	cout <<"[在复制构造函数内 perator= ]" << endl;
	if(this ==&c)   //考虑自己赋值给自己
		return *this;
	delete []hobby;  //释放以前指向的内容空间
	strcpy(name,c.name);
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight=c.weight;
	return *this;
}

Cow &Cow::operator=(const char *nm){
	cout <<"[operator=(const char *nm)内] \n";
	strncpy(name,nm,20);
	name[19]='\0';

	return *this;
} 






void Cow::ShowCow()const{
	cout <<"name:"<<name <<",hobby" <<hobby <<",weight:" <<weight <<endl;
}








