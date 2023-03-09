#include <iostream>
#include <fstream>
using namespace std;





int main(){

	ofstream fout;
	cout <<"Please enter a int:";
	int temp;
	cin >> temp;
	cin.get();

	fout.open("bin",ios_base::out |ios_base::binary);
	fout.write((char *)&temp,sizeof(int));
	fout.close();
	return -1;


	int num=555;
	ofstream fout;
	fout.open("filename",ios_base::out|ios_base::app|ios_base::binary);
	//打开文件 out + 追加 + 二进制模式



	fout.write((void*)&num, sizeof(num));
	//从哪里开始写，写多大
	//二进制写入 不能用 <<  得用 write 函数







}