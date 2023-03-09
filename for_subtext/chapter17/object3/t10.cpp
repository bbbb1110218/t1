#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){

	const char * filename="ManyNumber.txt";
	stringstream str;
	ifstream fin;
	fin.open(filename);

	char ch;

	long total=0;
	int n;


	while(fin.get(ch))
		str << ch;

	while(str >> n){
		cout << n << endl;

		total +=n;
	}

	fin.close();

	cout << "Total:" << total << endl;


	return 0;


}