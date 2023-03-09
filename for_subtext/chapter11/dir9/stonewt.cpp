#include "stonewt.h"


Stonewt::Stonewt(double p){
	pounds=p;
	stone=int(pounds) / RATE;
	left_pounds=p-stone*RATE;
	type_=STONE;
}

Stonewt::Stonewt(int s,double lp){
	stone=s;
	left_pounds=lp;
	pounds=s*RATE+left_pounds;
	type_=STONE;
}


void Stonewt::set_type(TYPE tp){
	type_=tp;
}


void Stonewt::set_type(int tp){
	switch(tp){
	case 0:type_=STONE;break;
	case 1:type_=POUNDS;break;
	case 2:type_=FLOATPOUNDS;break;

	}
}


ostream& operator<<(ostream&os,const Stonewt&s){
	if(s.type_==Stonewt::STONE){
		os <<s.stone <<" Stone," <<s.left_pounds <<" pounds.";
	}else if(s.type_ ==Stonewt::POUNDS){
		os << int(s.pounds) <<",pounds(int)";
	}else if(s.type_ ==Stonewt::FLOATPOUNDS){
		os << s.pounds <<",pounds(float)";
	}else{
		os <<"Invalid type";
	}
	return os; 
}