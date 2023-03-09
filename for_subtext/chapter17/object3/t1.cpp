#include <iostream>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

int main(){
	const char * file ="mysecert.txt";
	ifstream fin;

	char ch;
	fin.open(file);
	if(fin.is_open()){
		cout << "Here is the content of file:" <<file << endl;
		while(fin.get(ch))
			cout <<ch;
		fin.close();
		
	}else{
		return -1;
	}

	ofstream fout;
	fout.open(file,ios_base::out|ios_base::app);

	if(!fout.is_open()){
		cout << "Can't open " <<file << endl;
		exit(0);

	}

	cout << "enter new string append to the file" << endl;

	string str;
	while(getline(cin,str) && str.size() >0){
		fout <<str << endl;
	}

	fout.close();

	fin.clear(); //之前流缓存清除

	fin.open(file);
	if(fin.is_open()){
		cout << "Here is the content of file:" <<file << endl;
		while(fin.get(ch))
			cout <<ch;
		fin.close();
		
	}else{
		return -1;
	}


	return 0;
}