
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template<class T>
T average_list(initializer_list<T>  vlist){
	T sum{};
	size_t n=vlist.size();
	
	for(auto p=vlist.begin();p!=vlist.end();p++){
		sum += *p;
	}

	return sum/n;

}


int main(){
	auto q=average_list({15.4,10.7,90.0});
	cout <<q << endl;

	cout << average_list({20,30,19,17,45,38}) << endl;

	auto ad =average_list<double>({'A',70,65.33});
	cout << ad << endl;

	return 0;
}