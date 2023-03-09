
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;


int main(){

	stringstream Mystr; //内核格式化
	int temp;
	char ch;
	int sum=0; 




	ifstream fin;
	fin.open("file1");

	cout << "here is the content of " << filename << endl;
	while(fin.get(ch)){
		Mystr << ch;			 //类似cout 
	}

	while(Mystr >> temp){		//从对象读出来 stringstream

		cout << temp << endl;
		sum +=temp;
	}

	cout << "Sum:" << sum << endl;


	fin.close();

	return 0;


}