#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string file1("q1");

	string file2("q1.copy");

	

	ifstream fin(file1);

	ofstream fout(file2);

	if(!fin.is_open()){
		cout << file1 <<"error" << endl;
		return -1;
	}

	if(!fout.is_open()){
		cout << file2 <<"error" << endl;
		return -1;
	}

	char ch;
	while(fin.get(ch)){  //不跳过空白字符
		fout.put(ch);
	}

	fin.close();
	fout.close();

	return 0;

}
