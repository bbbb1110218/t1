#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;


class Store{
private:
	ofstream &fout;
public:
	Store(ofstream& out):fout(out){

	}


	void operator()(const string &str){
		size_t n=str.size();
		fout.write((char*)&n,sizeof(n));
		fout.write((char*)str.data(),n);

	}


};


void GetStrs(ifstream& fin,vector<string> & vstr);

void ShowStr(const string &str);

int main(){

	vector<string> vostr;

	string temp;

	cout <<"Enter string (empty line to quit):\n";
	while(getline(cin,temp) && temp[0] !='\0')
		vostr.push_back(temp);

	cout << "Here is your input:\n";

	for_each(vostr.begin(),vostr.end(),ShowStr);//need func ShowStr


	ofstream fout("string.dat",ios_base::out|ios_base::binary);

	for_each(vostr.begin(),vostr.end(),Store(fout));//What is Store??

	fout.close();

	vector<string> vistr;

	ifstream fin("string.dat",ios_base::in|ios_base::binary);
	if(!fin.is_open()){
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}

	GetStrs(fin,vistr);  //what is this

	cout << "\nHere are the string read from the file:\n";
	for_each(vistr.begin(),vistr.end(),ShowStr);



	return 0;
}

void ShowStr(const string &str){
	cout << str << endl;
}



void GetStrs(ifstream& fin,vector<string> & vstr){
	size_t n;
	char *data;
	while(fin.read((char*)&n,sizeof(size_t))){
		data=new char[n];
		fin.read(data,n);
		vstr.push_back(data);
		delete []data;

	}


}


