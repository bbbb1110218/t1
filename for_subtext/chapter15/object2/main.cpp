#include "tv.h"

int main(){
	TV Panda;
	cout <<"Initial setting for Panda Tv---" << endl;
	Panda.show_setings();
	Panda.onoff();
	Panda.show_setings();

	cout <<"----------"<< endl;
	Panda.volup();
	Panda.chanup();
	Panda.show_setings();

	cout <<"--Have a Remote--"<< endl;
	Remote rt;
	rt.set_channel(Panda,55);	
	for(int i=0;i<97;i++)
		rt.volup(Panda);
	for(int i=0;i<101;i++)
		rt.chanup(Panda);


	Panda.show_setings();
	rt.onoff(Panda);
	Panda.show_setings();
	


	return 0;
}