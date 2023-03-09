#include <iostream>
#include <cstring>
using namespace std;


class Temp{
private:
	char *str;
public:
	Temp():str("hello,kitty"){};
	Temp(const char *temp){strcpy(str,temp);}
	void say(){
		cout << str<< endl;
	}

};

int main(){
	Temp s("fuck,you");
	s.say();
	return 0;
}