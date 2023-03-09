
#include<iostream>
#include <string>
using namespace std;

int main(){
	string name("minliang");
	string::reverse_iterator ps;
	for(ps=name.rbegin(); ps !=name.rend(); ps++){
		cout << *ps;
	}

	cout << endl;
	cout << name.at(0) << endl;

	int n=stoi("10");

	double d=stoi("54.444");
	cout << n << endl;
	cout << d << endl;
	cout<< name.max_size() /1024/1024/1024/1024 << endl;
	

	return 0;

}