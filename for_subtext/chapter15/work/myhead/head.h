#ifndef __MYHEAD__H__
#define __MYHEAD__H__

#include <iostream>
using namespace std;

class Tv;

class Remote{
private:
	enum{HAVENO,HAVE};
	int _battery;


public:
	Remote():_battery(HAVENO){}
	void ChangeBattery(){_battery=HAVE;cout <<"Remote Change Battery" << endl;}
	bool SetChannel(Tv& tv,int ch);
	bool OnOffRemote(Tv& tv);
	void UpVolume(Tv& tv);
	void DownVolume(Tv& tv);
	void UpChannel(Tv& tv);
	void DownChannel(Tv& tv);
	void Display(Tv& tv);
	bool Battery(){
		if(!_battery){
			cout << "遥控电池没电" << endl;
			return false;
		}
		return true;}

	friend class TV;
};



class Tv{
private:
	enum{CLOSE,OPEN};
	enum{TV,DVD};
	enum{MINVOLUME,MAXVOLUME=20};
	enum{MINCHANNEL,MAXCHANNEL=100};
	int _state;				//状态开关
	int _volume;			//音量
	int _channel;			//频道
	int _mode;				//模式 tv dvd
	bool State(){return _state;}
	void UpVolume();
	void DownVolume();
	void UpChannel();
	void DownChannel();


public:

	Tv():_state(OPEN),_volume(5),_channel(18),_mode(TV){}
	bool OnOff();
	void ShowState()const;
	void ChangeBattery(Remote& m){
		m.ChangeBattery();
	}





	friend class Remote;

};







#endif