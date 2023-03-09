#ifndef __TV__H__ 
#define __TV__H__ 

#include <iostream>
using namespace std;

class TV{
private:
	enum{off,on};	//状态
	enum{MinVal,MaxVal=20}; //音量
	enum{MinChan=1,MaxChan=100}; //频道
	enum{tv,DVD};	//模式


	int state;	//状态
	int volume;	//音量
	int channel;	//频道
	int input;	// tv,DVD
public:
	TV(int s=off):state(s),volume(5),channel(2),input(tv){}
	void onoff(){state= (state == on) ?off:on;}
	bool volup();
	bool voldown(); //音量
	void chanup(); //channel up
	void chandown();
	void set_input(){input = (input == tv)?DVD:tv;}
	void show_setings()const;

						//重点
	friend class Remote;//Remote 所有方法 都可以访问TV类的 private 成员，protected 成员
						//两个类 不存在包含 和 所属关系
 						//但是某个类 的方法，可以访问另外一个类的私有成员和保护成员和public 成员
};

class Remote{ //遥控器
private:
	int mode;
public:
	Remote(int m=TV::tv):mode(m){};

	void onoff(TV&t){t.onoff();};//要操作哪一个电视
								//调用 类里面的函数
	bool volup(TV& t){return t.volup();}
	bool voldown(TV& t){return t.voldown();}
	void chanup(TV&t){ t.chanup();}
	void chandown(TV &t){ t.chandown();}
	void set_channel(TV &t,int c){t.channel=c;} //设置Tv的私有成员
	void set_input(TV &t){t.set_input();}

	void display(){
		cout <<"Remote Mode: " << (mode==TV::tv ?"tv":"DVD") << endl;
			}




};



#endif