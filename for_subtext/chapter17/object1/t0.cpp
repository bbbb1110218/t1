#include <iostream>
#include "t.cpp"
using namespace std;

extern int ti ;
void fuck();


extern template<class T>
class Myclass<T> ;

// extern class fuck;

int main(){
	cout << ti << endl;
	fuck();
	// heellomi mi(6);
	// mi.Show();

	return 0;
}