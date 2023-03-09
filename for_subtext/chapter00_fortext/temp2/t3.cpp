#include <iostream>
#include <fstream>
using namespace std;



int main(){
	ifstream fp;
	fp.open("t4.cpp",8);
	if(!fp){
		cout <<"Can't open the file" << endl;
		exit(-1);
	}
	string buffer;
	getline(fp,buffer,'\n');
	while(fp){
		cout << buffer << "换行";
		getline(fp,buffer,'\n');


	}
	return 0;

	
}


