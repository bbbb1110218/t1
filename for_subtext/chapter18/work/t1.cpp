#include <iostream>
#include <functional>
 
using namespace std;

template<class T>
void show2(double x, T&& fp){
	std::cout << x << " ->" << fp(x) << '\n';
}



int main(){
	function<double(double)> fuck=[](double x){return 1.8*x+32;};

	show2(18.0,[](double x){return 1.8*x+32;});
	return 0;
	
}
