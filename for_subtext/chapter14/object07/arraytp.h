#ifndef __ARRAYTP_H__
#define __ARRAYTP_H__



#include <iostream>

using namespace std;

template<class T,int n>
class ArrayTp{
private:
	T ar[n];
public:
	T &operator[](int i);	//可以读取并且修改
	T operator[](int i)const; //只能读取

};


template<class T,int n>
T& ArrayTp<T,n>::operator[](int i){  //加上作用域 ArrayTp<T,n>
	return ar[i];
}


template<class T,int n>
T ArrayTp<T,n>::operator[](int i)const{
	return ar[i];
}




#endif

