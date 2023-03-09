#include <iostream>
#include <string>



using namespace std;
template<class T>
void show(const T &t)noexcept;
void show(const char * t)noexcept;
void display(const char *t)noexcept;

template<>void show<string>(const string& t)noexcept;


int main(){
	string temp="hello";
	show(8); //使用模版
	show("hello,kitty"); //使用非模版
	display("hello,kitty");
	show(temp);
	return 0;
}

template<>void show<string>(const string& t)noexcept{
	cout <<"[ in special func of string ]" << t << endl;
}

void display(const char *t)noexcept{
	cout <<"in func display:" << t <<endl;
}

void show(const char * t)noexcept{
	std::cout <<"in func show:"<< t << std::endl;
}

template<class T>
void show(const T &t)noexcept{
	std::cout <<"in func show(template):"<< t << std::endl;
};




