#include <iostream>
using namespace std;

   template<class T1,class T2>
  class A{
    public:
    	void show(){cout <<"func 1|母方法" << endl;}
  };


template<class T2>
class A<int,T2>{
  public:
  	void show(){cout <<"当数据第一个为int类型的时候，用这种方法"<<endl;}
};

template<class T1>
class A<T1,double>{
  public:
  	void show(){cout <<"当数据第2个为double类型的时候，用这种方法"<<endl;}
};

int main(){
  A<char,char> t1;
  t1.show();
  A<int,char> t2;
  t2.show();
  A<char,double>t3;
  t3.show();
}
  