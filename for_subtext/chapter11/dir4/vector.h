#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
using namespace std;

namespace VECTOR{

	class Vector{
		public:
			enum Mode{RECT,POL}; //模式
		private:
			double x;
			double y;
			double mag;//长度
			double ang;//角度
			Mode mode;
			void set_mag();
			void set_ang();
			void set_x();
			void set_y();

		public:
			Vector();
			Vector(double n1,double n2,Mode form=Vector::RECT); //模式
			void reset(double n1,double n2,Mode form=Vector::RECT);
			double xval() const{return x;};
			double yval() const{return y;};
			double magval() const {return mag;};
			double angval() const {return ang;};
			void polar_mode();// set Mode
			void rect_mode();
			Vector& operator+(const Vector & b)const;
			Vector& operator-(const Vector & b)const;
			Vector& operator-() const;
			Vector& operator*(const double &n) const;

			friend Vector& operator*(const double &n, const Vector& a);
			friend ostream& operator<<(ostream &os,const Vector&v);





	};


};




#endif
