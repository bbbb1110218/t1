#include "vector.h"
#include <cmath>


namespace VECTOR{
	const double Rad_to_reg=45.0/tan(1.0);

/*
	void Vector::set_x(){
		x=abs * cos(angel);
	}

	void Vector::set_y(){
		y=abs * sin(angel);
	}

	void Vector::set_abs(){
		abs=sqrt(x*x+y*y);
	}

	void Vector::set_angel(){
		if(x==0.0 && y==0.0)
			angel=0;
		else
			angel=atan2(y,x); //TODO:有可能是错的
	}
*/	
	void Vector::set_x(const double &n1,const double &n2){
		x=n1*cos(n2/Rad_to_reg);
	}

	void Vector::set_y(const double &n1,const double &n2){
		y=n1*sin(n2/Rad_to_reg);
	}

	double Vector::get_abs()const{
		return sqrt(x*x + y*y);
	};

	double Vector::get_angel()const{
		return atan2(y,x);

	};



	Vector::Vector(const double &n1,const double &n2,TYPE _type){
		type=_type;
		if(type==RECT){
			x=n1;
			y=n2;
		}else if(type ==POL){
			set_x(n1,n2);
			set_y(n1,n2);
		}else{
			cout <<"in 构造函数 ERROR" << endl;
		}
	}


	void Vector::reset(const double &n1,const double &n2,TYPE _type){
		*this = Vector(n1,n2);
	}


	Vector Vector::operator+(const Vector & v1) const{
		return Vector(x+v1.x,y+v1.y);
		
	}



	Vector Vector::operator-(const Vector & v1) const{
		return Vector(x-v1.x,y-v1.y);
	}


	Vector Vector::operator-(){
		return Vector(-x,-y);
	}

	//
	Vector Vector::operator*(const double &n){
		return Vector(x*n,y*n);
	}




	ostream& operator<<(ostream& os,const Vector&v){

			os << "type:"<< v.type <<"[ x:"<<v.x <<",y: "<<v.y ;
			os << ", abs:" << v.get_abs() << ",angel:" << v.get_angel() <<"]"<<endl;
		return os;
	}



}