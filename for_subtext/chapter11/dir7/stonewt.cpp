#include "stonewt.h"



Stonewt::Stonewt(){
	stone = pds_left =pounds = 0;
}

Stonewt::Stonewt(double lbs){
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn +lbs -int(lbs);
	pounds =lbs;
};

Stonewt::Stonewt(int stn,double lbs){
	stone=stn;
	pds_left=lbs;
	pounds=stn * Lbs_per_stn + lbs;
};

void Stonewt::show_lbs() const{
	cout <<pounds<<" pounds."<< endl;

};

void Stonewt::show_stn()const{
	cout <<stone <<" stone, "<< pds_left <<" pounds.\n";
}


Stonewt::operator int() const {

	 return (int)(pounds + 0.5);

}


Stonewt::operator double() const{
	return pounds;	
}


Stonewt::operator string() const{
	string temp= "[hello,kitty:" + to_string(stone) + "]";

	return temp;
}

Stonewt operator+(const Stonewt &s1,const Stonewt &s2){
	Stonewt temp(s1.pounds + s2.pounds);
	return temp;

}

Stonewt Stonewt::operator*(const double &n){
	Stonewt temp;

	temp.pounds =pounds*n;
	temp.stone =int(stone * n) / Lbs_per_stn;
	temp.pds_left = int(stone *n ) % Lbs_per_stn + (stone * n) - int(stone * n);
	return temp;
}

//友元函数
Stonewt operator*(const double&n,const Stonewt &s){
	return s*n;

}
