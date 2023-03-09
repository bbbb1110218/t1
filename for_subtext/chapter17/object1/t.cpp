#include <iostream>



int ti=6;
void fuck(){
	std::cout << "Fuck your" << std::endl;
}


template<class T>
class Myclass{
private:
	T value;
public:
	Myclass(T v):value(v){}
	void Show(){
		std::cout << "value is " << value << std::endl;
	}

};


class fuck{
public:
	void sayhellokitty(){
		std::cout << "value is " << 0 << std::endl;
	}
};