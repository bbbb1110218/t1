#include <iostream>
#include <fstream> //文件流
#include <string>
#include <cstdlib>


using namespace std;

int main(){
	ifstream fin;   //input stream
	fin.open("temp.txt");

	if(fin.is_open() ==false){

		cerr << "Can't open the file" << endl;  //cerr 只能打印到屏幕上 不能重定向
		exit(EXIT_FAILURE);
	}

	string item;
	int count =0;

	getline(fin,item,':');//遇到 ：就停止
	while(fin){
		++count;
		cout << count  << ":" << item << endl;
		getline(fin,item,':');//遇到 ：就停止
	}

	fin.close();







	return 0;
}