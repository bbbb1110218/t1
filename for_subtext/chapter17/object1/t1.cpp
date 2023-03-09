#include <iostream>
#include <string>
using namespace std;
int main(){

	cout << "what your name:" ;
	string name;
	getline(cin,name);

	std::cout << "hello,kitty," << name <<std::endl;
	return 0;
}