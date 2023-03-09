#include "vector.h"
#include <cmath>


namespace VECTOR{
	const double Rad_to_reg=45.0/tan(1.0);

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

	Vector::Vector(const double &n1,const double &n2,TYPE _type){
		type=_type;
		if(type==RECT){
			x=n1;
			y=n2;
			set_abs();
			set_angel();
		}else if(type ==POL){
			abs=n1;
			angel=n2/Rad_to_reg;
			set_x();
			set_y();
		}else{
			cout <<"in 构造函数 ERROR" << endl;
		}
	}


	void Vector::reset(const double &n1,const double &n2,TYPE _type){
		*this = Vector(n1,n2,_type);
	}


	Vector Vector::operator+(const Vector & v1) const{
		return Vector(x+v1.x,y+v1.y,type);
		
	}



	Vector Vector::operator-(const Vector & v1) const{
		return Vector(x-v1.x,y-v1.y,type);
	}


	Vector Vector::operator-(){
		return Vector(-x,-y,type);
	}

	//
	Vector Vector::operator*(const double &n){
		return Vector(x*n,y*n,type);
	}




	ostream& operator<<(ostream& os,const Vector&v){
		if(v.type == Vector::RECT){
			os << "type:"<< v.type <<"[ x:"<<v.x <<",y: "<<v.y;
			os << ", abs:"<< v.abs <<",angel: "<< v.angel <<"]"<< endl;
		}else if(v.type==Vector::POL){
			os << "type:"<< v.type <<"[abs:"<< v.abs <<",angel: "<< v.angel;
			os <<" ,x:"<<v.x <<",y: "<<v.y <<"]" << endl;

		}else{
			os << "Type error" <<endl;
		}
		return os;
	}



}