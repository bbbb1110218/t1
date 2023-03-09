#include <iostream>

using namespace std;


template <class T1>
class Big{
private:
	template <class T2> //私有模版类
	class Small;

	Small<T1> q; //数据成员1
	Small<int> n;	//数据成员2
public:
	Big(T1 t,int nv):q(t),n(nv){}

	void Show()const{q.show();n.show();}

	template<class U> //成员函数模版
	U get_value(U u,T1 tt)const;
};


template<class T1>
template<class T2>
class Big<T1>::Small{ //Big<T1>类里面的类
private:
	T2 t;
public:
	Small(T2 n):t(n){}
	void show()const{cout << t << endl;}
	T2 Value()const{return t;}
};


template<class T1>
template<class U>
U Big<T1>::get_value(U u,T1 tt)const{ //Big<T1>类里面的成员函数
	return (q.Value() + n.Value())* tt/u;};



int main(){

	Big<double> bb(6.5,5);
	bb.Show();
	cout << "get_value() : " <<bb.get_value(3,3.4) << endl;
	cout << "get_value(2) : " <<bb.get_value(3.0,3.4) << endl;

	return 0;
}