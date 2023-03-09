#include <iostream>

class Num{
	private:
	 int n;
	public:
		Num(){n=0;};
		Num(int argn);
		Num& operator+=(int argn);
		Num& operator+(const Num& N2);
		void show();
		~Num();
		

};