#ifndef __TV__H__ 
#define __TV__H__ 

#include <iostream>
using namespace std;


class TV;


class Remote{ //遥控器
private:
	int mode;
	enum{off,on};	//状态
	enum{MinVal,MaxVal=20}; //音量
	enum{MinChan=1,MaxChan=100}; //频道
	enum{tv,DVD};	//模式
public:
	Remote(int m=tv):mode(m){};

	void onoff(TV&t);
								//调用 类里面的函数
	bool volup(TV& t);
	bool voldown(TV& t);
	void chanup(TV&t);
	void chandown(TV &t);
	void set_channel(TV &t,int c); //设置Tv的私有成员
	void set_input(TV &t);

};



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

						
	friend void Remote::set_channel(TV &t,int c);
										//
};
inline 
void Remote::onoff(TV&t){t.onoff();};//要操作哪一个电视
inline						//调用 类里面的函数
bool Remote::volup(TV& t){return t.volup();}
inline
bool Remote::voldown(TV& t){return t.voldown();}
inline
void Remote::chanup(TV&t){ t.chanup();}
inline
void Remote::chandown(TV &t){ t.chandown();}
inline
void Remote::set_channel(TV &t,int c){t.channel=c;} //设置Tv的私有成员
inline
void Remote::set_input(TV &t){t.set_input();}



#endif