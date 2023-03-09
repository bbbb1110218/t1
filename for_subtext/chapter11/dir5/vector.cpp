#include "vector.h"
#include <cmath>

namespace VECTOR{

const double Rad_to_reg=45.0 / atan(1.0);

void Vector::set_abs(){

	abs=sqrt(x*x +y*y);

}

void Vector::set_angel(){
	if(x==0.0 && y==0.0)
		angel=0;
	else
		angel=atan2(y,x); //TODO:有可能是错的
}

void Vector::set_x(){
	x=abs * cos(angel);
}


void Vector::set_y(){
	y=abs * sin(angel);
}






Vector::Vector(){
	x = y = angel = abs = 0;
	type=RECT;
}

Vector::Vector(const double &n1,const double &n2,TYPE type_){
	type=type_;
	if(type==RECT){
		x=n1;
		y=n2; 
		set_angel();
		set_abs();

	}else if (type == POL){
		abs=n1;
		angel=n2 / Rad_to_reg;

		set_x();
		set_y();
	}else{
		cout <<"Type Error,已经初始化" << endl;
		x=y=abs=angel=0;
		type=RECT;
	}
}

void Vector::resett(const double &n1,const double &n2,TYPE type_){
	type=type_;
	if(type==RECT){
		x=n1;
		y=n2; 
		set_angel();
		set_abs();

	}else if (type == POL){
		abs=n1;
		angel=n2 / Rad_to_reg;

		set_x();
		set_y();
	}else{
		cout <<"Type Error,已经初始化" << endl;
		x=y=abs=angel=0;
		type=RECT;
	}
}


Vector Vector::operator+(const Vector &v)const{
	return Vector(x+v.x,y+v.y);
}

Vector Vector::operator-(){
	return Vector(-x,-y);
}
Vector Vector::operator-(const Vector &v){
	return Vector(x-v.x,y-v.y);
}


Vector Vector::operator*(const double & num){
	return Vector(num *x,num *y);
}

Vector operator*(const double & num, const Vector &v){
	return Vector(v.x *num,v.y*num);
}

Vector Vector::operator+(const double &n){
	return Vector(x+n,y+n);
}



ostream& operator<<(ostream &os,Vector &v){
	//if(v.type ==Vector::RECT)
	//	os<< "x,  y=" << v.x <<",  " << v.y << endl;
	//else if(v.type==Vector::POL)
	//	os <<"abs, angel = " <<v.abs <<", " << v.angel<< endl;
	//else
	//	os <<"Type error"<<endl;
		os <<"[mode = " << v.type <<", x = " << v.x << " ,y = " << v.y <<" , abs = ";
		os << v.abs  << " ,angel = " << v.angel <<"]"<< endl;  
	return os;
}

Vector& Vector::operator+=(const Vector &v){
	x=x+v.x;
	y=y+v.y;
	set_abs();
	set_angel();
	return *this;

}



Vector::~Vector(){
	;//cout <<"Hello,kitty"<< endl;
}














}