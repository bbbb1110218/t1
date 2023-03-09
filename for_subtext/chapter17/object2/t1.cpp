#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
	fstream 包含iostream

	流状态检查
	is_open()


	
	clear(); 清空之间的缓冲 reset filestream;
				先清空 再关闭
	close(); 关闭文件

	操作两个文件，要创建两个文件流



*/

int main(){

	string filename;  
	cout  << "Enter the name of new file:" ;
	cin >> filename; 

	ofstream fout; 		  //输出流
	fout.open(filename);  //默认 "w"模式

	if(!fout.is_open()){ //检查文件是否打开
		cout << filename << " Create faild" << endl;
		return -1;
	}

	//fout 和cout 一样用
	fout << "for your eyes only" << endl;

	double secert;
	cout << "your secert number is:";
	cin >> secert;
	fout << "my secret number is " << secert << endl;



	fout.close();

	ifstream fin;
	fin.open(filename);
	cout << "Here is content of " <<filename << ":" << endl;
	char ch;
	while(fin.get(ch)){   //和 cin 一样的用法
		cout << ch;
	}

	fin.close();








	return 0;
}