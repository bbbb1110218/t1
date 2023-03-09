#include <iostream>
using namespace std;

namespace VECTOR{


	class Vector{
	public:
		enum TYPE{RECT,POL};
	private:
		double x;
		double y;
		TYPE type;
		void set_x(const double &n1,const double &n2);
		void set_y(const double &n1,const double &n2);

	public:

		Vector(){x=y=0;type=RECT;};
		Vector(const double &n1,const double &n2,TYPE _type=RECT);

		void rect_mode(){type=RECT;};
		void pol_mode(){type=POL;};


		

		void reset(const double &n1,const double &n2,TYPE _type=RECT);
		double get_abs()const;
		double get_angel()const;
		double get_x()const {return x;};
		double get_y()const {return y;};


		Vector operator+(const Vector & v1) const;
		Vector operator-(const Vector & v1) const;
		Vector operator-();
		Vector operator*(const double &n);

		friend ostream& operator<<(ostream& os,const Vector&v);

	};
}