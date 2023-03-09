
#ifndef __WINE_E__
#define __WINE_E__

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

template<class T1,class T2>class Pair; //告诉编译器有这么个类；声明


typedef valarray<int> Arrayint;
typedef Pair<Arrayint,Arrayint> PairArray; //代码之前没有 Pair


template<class T1,class T2>
class Pair{
private:
	T1 a;
	T2 b;
public:
	Pair(const T1& aval,const T2& bval):a(aval),b(bval){}
	T1& first();
	T2& second();
	T1 first()const {return a;}
	T2 second()const {return b;}
};

template<class T1,class T2>		//可以直接修改，当作左值
T1& Pair<T1,T2>::first(){
	return a;
}


template<class T1,class T2>
T2& Pair<T1,T2>::second(){
	return b;
}

class Wine:private PairArray,private string{
private: 
	
	int iYear;
public:
	Wine(const char *l,int y);
	Wine(const char *l,int y,const int year[],const int bot[]);
	void Getbotts();//具体哪些年份
	const string &Label()const;
	int Sum()const;
	void Show()const;
};




#endif













