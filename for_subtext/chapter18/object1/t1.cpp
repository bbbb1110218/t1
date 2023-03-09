
#include <iostream>

#include <utility>

using namespace  std;

class Foo{
public:
    int value;
public:
    Foo(int n):value(n){cout << " 默认构造函数|"<< value << endl;}

    Foo(const Foo& old):value(old.value){cout << " 拷贝构造函数" << endl;}

    Foo(Foo&& f):value(f.value){
    	cout << " 右值构造函数" << endl;
    	f.value=0;
    }

    Foo& operator=(Foo&&f){
    	this->value=f.value;
    	//f.value=0;
    	return *this;
    }

    Foo operator+(const Foo&f){
        return Foo(value +f.value);
    }

    int Value()const 
    {return value;}
};


int main(){
    Foo a(1);
    Foo b(2);
   	b=std::move(a+100);
   	cout << a.Value() << endl;
   	cout << b.Value() << endl;



    return 0;
}