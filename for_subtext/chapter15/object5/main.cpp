#include <iostream>
using namespace std;

class T2; //提前前置声明 防止T1不认识

class T1{
private:
	int val;
public:
	T1(int n=0):val(n){}
	friend int sync(T1 &t1,T2 &t2); //没见过T2 类，需要前置声明
	friend int sync(T2& t2,T1&t1);		//需要重载 两个类 谁在前 谁在后
};

class T2{
private:
	int value;
public:
	T2(int n):value(n){}
	friend int sync( T1 &t1,T2 &t2);
	friend int sync(T2& t2, T1&t1);
	
};

inline int sync( T1 &t1,T2 &t2){
	return t1.val +t2.value;
}

inline int sync(T2& t2, T1&t1){
	return sync(t1,t2);
}


int main(){
	T1 t1(20);
	T2 t2(30);
	int val=sync(t1,t2);
	int val2=sync(t2,t1);//用到重载的原因，两个类的参数特征标不一样
	cout << val << endl;
	cout << val2 << endl;
	return 0;
}