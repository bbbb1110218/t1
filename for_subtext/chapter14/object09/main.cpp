#include <iostream>
#include <string>

using namespace std;


template<class T>
class Beta{
private:
	
	template<class V> //私有函数里面定义一个类模版
	class hold{
	private:
		V value;
	public:
		hold(V v=0):value(v){}
		void show () const{cout << value<< endl;}
		V Value()const{return value;}
	};

	hold<T> q;
	hold<int> n;
public:
	Beta(T t,int i):q(t),n(i){}
	void Show() const{q.show();n.show();}
	void Show2()const{cout <<"T:" << q.Value() <<" , int:" << n.Value();}
	
	template<class U>//函数模版 U没规定类型，T是类已经传递进来的类型
	U blab(U u,T t){return (q.Value() + n.Value())*u/t;}
};


int main(){

	Beta<double> guy(5.6,5);
	cout <<"T set to double" << endl;
	guy.Show();
	//guy.Show2();

	cout <<"V==T,the are all double,U set to int" << endl;
	cout << guy.blab(4,5.6) << endl;

	cout <<"V==T,the are all double,U set to double" << endl;
	cout << guy.blab(4.0,5.6) << endl;


	
	return 0;
}