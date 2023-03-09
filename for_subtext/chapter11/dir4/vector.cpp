#include "vector.h"
#include "cmath"


namespace VECTOR{

	const double Rad_to_reg=45.0 / atan(1.0);

void Vector::set_mag(){

	mag= sqrt(x*x +y*y); 

};

void Vector::set_ang(){
	if(x==0.0 && y==0.0)
		ang=0.0;
	else
		ang=atan2(y,x);

}
void Vector::set_x(){
	x=mag * cos(ang);
}
void Vector::set_y(){
	y=mag* sin(ang);
}

Vector::Vector(){
	x=y=mag=ang=0.0;
	mode=RECT;
}

Vector::Vector(double n1,double n2,Mode form){
	mode=form;
	if(form == RECT){
		x=n1;
		y=n2;
		set_mag();
		set_mag();
	}else if(form ==POL){
		mag=n1;
		ang=n2 / Rad_to_reg;
		set_x();
		set_y();
	}
	else{
		cout <<"Form Error" <<endl;
		Vector();
	}

}

void Vector::reset(double n1,double n2,Mode form){
	mode=form;
	if(form == RECT){
		x=n1;
		y=n2;
		set_mag();
		set_mag();
	}else if(form ==POL){
		mag=n1;
		ang=n2 / Rad_to_reg;
		set_x();
		set_y();
	}
	else{
		cout <<"Form Error" <<endl;
		Vector();
	}

}




ostream& operator<<(ostream &os,const Vector&v){
	os << "[x=" << v.x ;
	os << ", y=" << v.y ;
	os << ", mag=" << v.mag ;
	os << ", ang=" << v.ang << "] "<<endl;
	return os;

}

Vector& operator+(const Vector & b)const{
	Vector temp;
	temp.x = x+ b.x;
	temp.y = y +b.y;
	temp.mode=mode;
	temp.set_mag();
	temp.set_ang();
	return temp;


}
Vector& operator-(const Vector & b)const{
	Vector temp;
	temp.x = x - b.x;
	temp.y = y - b.y;
	temp.mode=mode;
	temp.set_mag();
	temp.set_ang();
	return temp;
}

Vector& operator-() const{
	Vector temp;
	temp.x = 0 - this->x;
	temp.y = 0 - this->y;
	temp.mode=this->mode;
	temp.set_mag();
	temp.set_ang();
	return temp;

}
Vector& operator*(const double &n) const{
	Vector temp;
	temp.x =x *n;
	temp.y= x*n;
	temp.mode=mode;
	temp.set_mag();
	temp.set_ang();
}




};