#include <iostream>
#include <cmath>
#include <utility>
using namespace std;



class Myclass{
private:
	int value;

public:
	Myclass()=delete;
	Myclass(int n):value(n){}
	Myclass(const Myclass& Mc){value=Mc.value;}
	Myclass(Myclass&& Mcr){value=Mcr.value;Mcr.value=0;}
	Myclass operator+(const Myclass&mc){

		return Myclass(this->value+mc.value);
	}
	Myclass operator+(int &n){

		return Myclass(this->value+n);
	}
	Myclass& operator=(const Myclass& Mc){value=Mc.value; return *this;}
	Myclass& operator=(Myclass&& Mcr){value=Mcr.value;Mcr.value=0;cout << "|||" <<  endl;return *this;}
	void Display(){cout << "value:" << value << endl;}

};


int main(){
	Myclass t1(6);
	Myclass t2(4);
	Myclass t3(0);
	Myclass t4(0);
	Myclass t6;

	t3=t1+t2;			//调用移动赋值运算符
	t4=move(t1);

	t1.Display();
	t3.Display();
	t4.Display();
	
	return 0;
}