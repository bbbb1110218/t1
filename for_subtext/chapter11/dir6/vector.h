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
		double angel;
		TYPE type;
		void set_x();
		void set_y();
		void set_abs();
		void set_angel();

	public:

		Vector(){x=y=abs=angel=0;type=RECT;};
		Vector(const double &n1,const double &n2,TYPE _type=RECT);

		void rect_mode(){type=RECT;};
		void pol_mode(){type=POL;};
		

		void reset(const double &n1,const double &n2,TYPE _type=RECT);
		double get_abs()const{return abs;};
		double get_angel()const{return angel;};
		double get_x()const {return x;};
		double get_y()const {return y;};


		Vector operator+(const Vector & v1) const;
		Vector operator-(const Vector & v1) const;
		Vector operator-();
		Vector operator*(const double &n);

		friend ostream& operator<<(ostream& os,const Vector&v);

	};
}