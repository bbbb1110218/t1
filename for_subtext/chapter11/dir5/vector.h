#ifndef __VECTOR__H__
#define __VECTOR__H__


#include <iostream>
using namespace std;


namespace VECTOR{

	class Vector{
	public:
		enum TYPE{RECT,POL};
	private:
		double x;
		double y;
		double abs;
		double angel;//角度
	
		TYPE type;
		void set_abs();
		void set_angel();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(const double &n1,const double &n2,TYPE type_=RECT);
		void resett(const double &n1,const double &n2,TYPE type_=RECT);

		double xval()const {return x;};
		double yval()const {return y;};
		double absval()const {return abs;};
		double angelval()const {return angel;};
		void rectmode(){type=RECT;};
		void polmode(){type=POL;};
		double get_abs(){return abs;};
		~Vector();

		Vector operator-();
		Vector operator-(const Vector &v);
		Vector operator+(const Vector &v)const;
		Vector& operator+=(const Vector &v);
		Vector operator+(const double &n);


		Vector operator*(const double & num);


		friend Vector operator*( const double & num, const Vector &v);
		friend ostream& operator<<(ostream &os,Vector &v);




	};



};

#endif