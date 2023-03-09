#include <iostream>
#include <functional>
#include <array>
const int Size=5;

template<class T>
void sum(std::array<double,Size> a,const T&fp);



class Addr{
	private:
		double tot;
	public:
		Addr(double q=0):tot(q){}
		void operator()(double w){tot +=w;}
		double tot_v()const {return tot;}
};


int main(){
	// double total=0.0;
	// Addr ad(total);
	// std::array<double,Size> temp_c={32.1,34.3,37.8,35.2,34.7};
	// sum(temp_c,ad);
	// total=ad.tot_v();
	// std::cout << "total = " << ad.tot_v() << std::endl;
	// return 0;

	

	double total=0.0;
	std::function<void(double)> pf=[&total](double x){total+=x;};
	std::array<double,Size> temp_c={32.1,34.3,37.8,35.2,34.7};
	sum(temp_c,[&total](double x){total+=x;});
	std::cout << total << std::endl;

	return 0;

}


template<class T>
void sum(std::array<double,Size> a,const T &fp){


	for(auto pt=a.begin();pt<a.end();pt++){
		fp(*pt);
	}
}