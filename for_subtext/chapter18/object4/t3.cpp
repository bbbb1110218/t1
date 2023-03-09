#include <iostream>

using namespace std;

void show_list(){};

template<class T>
void show_list(const T &t){
	cout << t << endl;
} 

template<class T,class... Args>
void show_list(const T &t,Args... args){
	cout << t <<" ,";
	show_list(args...);
}

int main(){
	const char * hello="hello,kitty";
	show_list(1,3,"hello",2.3,4.5);
	show_list(hello);
	return 0;
}