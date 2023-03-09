
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

	string filename;
	cout << "Enter the file name:";
	cin >> filename;


	ifstream fin;
	fin.open(filename);
	char ch;
	int sum=0;
	cout << "here is the content of " << filename << endl;
	while(fin.get(ch)){
		cout.put(ch);
		sum +=ch;
	}

	cout << "Sum:" << sum << endl;


	fin.close();

	return 0;


}