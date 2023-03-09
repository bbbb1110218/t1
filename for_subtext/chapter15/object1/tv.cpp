#include "tv.h"

bool TV::volup(){
	if(volume < MaxVal){
		volume++;
		return true;
	}else 
		return false;
}

bool TV::voldown() //音量
{
	if(volume>MinVal)
	{
		volume--;
		return true;
	}else
		return false;
}
void TV::chanup()//channel up
{

	if(channel < MaxChan)
		channel++;
	else
		channel=MinChan;
}

void TV::chandown(){
	if(channel > MinChan)
		channel--;
	else
		channel=MaxChan;
}

void TV::show_setings()const{
	cout <<"TV is " << (state==on ? "on" : "off") << " ";
	if(state ==on){
		cout << ", volume:" << volume ;
		cout <<", channel:" << channel ;
		cout << ", Mode:" << (input == tv ?"TV":"DVD") << endl; 
	}else
		cout << "."<<endl;
}





