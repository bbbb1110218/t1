//4.Person类保存人的名和姓。除构造函数外，它还有Show( )方 法，用于显示名和姓。
//Gunslinger类以Person类为虚基类派生而来，
// 它包 含一个Draw( )成员，该方法返回一个double值，表示枪手的拔枪时间。 这
// 个类还包含一个int成员，表示枪手枪上的刻痕数。f
// 最后，这个类还包 含一个Show( )函数，用于显示所有这些信息。
//PokerPlayer类以Person类为虚基类派生而来。它包含一个Draw( )成 员，
//该函数返回一个1~52的随机数，用于表示扑克牌的值(也可以定 义一个Card类，
//其中包含花色和面值成员，然后让Draw( )返回一个Card 对象)。
//PokerPlayer类使用Person类的show( )函数。BadDude( )类从 Gunslinger和PokerPlayer类公有派生而来。
//它包含Gdraw( )成员(返回坏 蛋拔枪的时间)和Cdraw( )成员(返回下一张扑克牌)，另外还有一个 合适的Show( )函数。
//请定义这些类和方法以及其他必要的方法(如用于 设置对象值的方法)，并使用一个类似于程序清单14.12的简单程序对 它们进行测试。

#ifndef __MYHEAD__H__
#define __MYHEAD__H__
#include <iostream>
#include <string>
using namespace std;

class Card{
	int count;
public:
	// Card();
	Card(int t):count(t){};
	//Card& Next();
	friend ostream& operator<<(ostream &os,Card &c);
};


class Person{
private:
	string fName; //first name
	string sName;	//Second name

public:
	Person(string s1,string s2):fName(s1),sName(s2){}
	virtual void show()	const;
	virtual ~Person(){}
};

class Gunslineger:virtual public Person{
private:
	int scratch; //枪上的划痕
public:
	Gunslineger(string s1,string s2,int stime):Person(s1,s2),scratch(stime){}
	Gunslineger(const Person &p,int stime):Person(p),scratch(stime){}
	int Draw()const;
	virtual void show()const;
	virtual ~Gunslineger(){}

};

class PokerPlayer:public virtual Person{
public:
	PokerPlayer(string s1,string s2):Person(s1,s2){}
	PokerPlayer(const Person& p):Person(p){}
	Card Draw()const; //TODO 返回纸牌类
	virtual void show()const;
	virtual ~PokerPlayer(){}
};

class BadDude:public Gunslineger,public PokerPlayer{
public:
	BadDude(string s1,string s2,int stime):Person(s1,s2),Gunslineger(s1,s2,stime),PokerPlayer(s1,s2){}
	void show()const;
	virtual ~BadDude(){}
};




#endif