#ifndef __TV__H__ 
#define __TV__H__ 

#include <iostream>
using namespace std;


class TV; // 前置声明


class Remote{ //遥控器
private:
	int mode;

							//此类方法中用到了enum 拷贝一份enum 的变量
	enum{off,on};	
	enum{MinVal,MaxVal=20}; 
	enum{MinChan=1,MaxChan=100}; 
	enum{tv,DVD};	//模式
public:
	Remote(int m=tv):mode(m){};

	void onoff(TV&t);
								//调用 类里面的函数
	bool volup(TV& t);			//方法都需要定义在最下面 前置声明之声明了类，没有声明方法
								//方法需要放在最下面，并且 加上 inline 关键字 声明为内联函数
	bool voldown(TV& t);
	void chanup(TV&t);
	void chandown(TV &t);
	void set_channel(TV &t,int c);
	void set_input(TV &t);
	void display();

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

	// 定义了两个类方法为友元函数					
	friend void Remote::set_channel(TV &t,int c);  //Remote 需要放在 前面，要不然不认识
	friend void Remote::display();
};

inline //使之成为内联函数，和定义在类中一样
void Remote::onoff(TV&t){t.onoff();};
							
inline 
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

inline
void Remote::display(){
	cout <<"Remote Mode: " << (mode==tv ?"tv":"DVD") << endl;
		}


#endif