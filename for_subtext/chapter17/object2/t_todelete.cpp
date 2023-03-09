#include <iostream>
#include <fstream>
using namespace std;


int main(){
	// ofstream fout("todelete.txt");
	// if(!fout.is_open()){
	// 	cout << "can't open" << endl;
	// 	fout.clear();
	// 	fout.close();
	// 	return -1;
	// }
	// int a=88;
	// int *p=new int;
	// *p=45;

	// cout << "stack pointer " << &a << endl;
	// cout << "heap pointer " << (void *)p << endl;

	// cout <<"file pointer "<< fout << endl;
	// delete p;

	// for(int i=0;i<10;i++){
	// 	fout <<"just for text " << i+1 << endl;

	// }

	// fout.close();

	ofstream fout;
	fout.open("todelete.txt",ios_base::out +32);
	fout << "newline---\n";
	fout.close();
	return 0;
}