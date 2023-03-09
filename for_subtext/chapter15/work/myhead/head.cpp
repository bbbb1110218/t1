#include "head.h"



void Tv::ShowState()const{
	cout << "------------------------------------------------" << endl;
	if(_state){
			cout <<"TV  state :" <<  (_state == OPEN? "OPEN":"CLOSE")  << endl;
			cout <<"TV  volume:" << _volume << endl;
			cout <<"TV channel:" << _channel << endl;
			cout <<"TV   mode :" << (_mode == TV ? "TV":"DVD" ) << endl;
	}else
			cout <<"TV  state :" <<  (_state == OPEN? "OPEN":"CLOSE")  << endl;

}

bool Tv::OnOff(){
	_state=(_state == OPEN ? CLOSE:OPEN);
	return true;

}

void Tv::UpVolume(){
	
	if (_volume + 1 <= MAXVOLUME )
			_volume +=1;
	else
		_volume =MAXVOLUME;

}

void Tv::DownVolume(){
	if (_volume - 1 > MINVOLUME )
			_volume -=1;
	else
		_volume = MINVOLUME;

}

void Tv::UpChannel(){
	if(_channel + 1 > MAXCHANNEL)
		_channel = MINCHANNEL;
	else
		_channel += 1;
}

void Tv::DownChannel(){
	if(_channel - 1 < MINCHANNEL)
		_channel = MAXCHANNEL;
	else
		_channel -= 1;

}







void Remote::UpVolume(Tv& tv){
	if(!Battery()){
		return ;	
	}

	tv.UpVolume();
	}


void Remote::DownVolume(Tv& tv){
	if(!Battery())
		return;
	tv.DownVolume();
}

void Remote::UpChannel(Tv& tv){
	if(!Battery()) return;
	tv.UpChannel();
}

void Remote::DownChannel(Tv& tv){
	if(!Battery()) return;
	tv.DownChannel();
}

void Remote::Display(Tv& tv){
	if(!Battery()) return;
	tv.ShowState();
}


bool Remote::SetChannel(Tv& tv,int ch){
	if(!Battery()) return false;
	else if(!tv.State()){
		cout << "Tv is closed(by remote)" << endl;
		return false;
	}else if(ch < Tv::MINVOLUME || ch >Tv::MAXCHANNEL){
		cout << "Tv channel invalid (by remote)" << endl;
		return false;
	}else{
		tv._channel =ch;
		return true;
	}

}

bool Remote::OnOffRemote(Tv& tv){
	return tv.OnOff();
}


