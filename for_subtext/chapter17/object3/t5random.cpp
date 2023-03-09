#include <iostream>
#include <fstream>
#include <iomanip>  //设置小数点

using namespace std;

struct planet{
	char name[20];
	double population;
	double g;
};


int main(){
	const char * filename="planet.dat";
	planet pl;

	cout <<fixed;

	fstream finout; //输入流和输出流 定义成 fstream 

	int ct=0;

	finout.open(filename,ios_base::in|ios_base::out|ios_base::binary);

	if(finout.is_open()){
		cout << "Here is the content of file:" << filename << endl;
		while(finout.read((char *)&pl,sizeof(pl))){
			cout << "Ct Num : " << ct++ <<" ,Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"<<setprecision(2)  <<pl.g << endl;
		}
		
	}


	if(finout.eof())
		finout.clear(); 
	//读到文件尾了，会促发eofbit 标志为 会禁止对文件做进一步的读写
	//需要用clear() 重写设置文件流,清除标志位

	cout <<"Enter the Number you wish to change";
	int rec;
	cin >> rec;

	while(cin.get() !='\n'); //交替输入 干掉回车换行

	if(rec < 0 | rec >=ct ){
		cout <<"out of range!" << endl;
		exit(0);
	}


	streampos place=rec*sizeof(pl);//需要跨过的字节

	//seekg 输入指针 移动到指定的位置	ifstream   读取文件  fin >>到屏幕
	
	//seekp 输出指针 移动到指定的位置   ofstream   写文件    cout << data;

	finout.seekg(place); 
	finout.read((char*)&pl,sizeof(pl));	
	cout <<"the change of the data" << endl;
	cout << "rec : " << rec <<" ,Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"<<setprecision(2)  <<pl.g << endl;
	if(finout.eof())
		finout.clear();

	cout << "enter Plant Name:" ;
	cin >> pl.name;
	while(cin.get() !='\n');
	cout << "enter planet population:";
	cin >> pl.population;
	cout << "enter planet G ";
	cin >> pl.g;
	while(cin.get() !='\n');

	finout.seekp(place);
	finout.write((char *)&pl,sizeof(pl));

	finout.seekg(0);
	//重写读取文件
	ct=0;

	if(finout.is_open()){
		cout << "Here is the content of file:" << filename << endl;
		while(finout.read((char *)&pl,sizeof(pl))){
			cout << "Ct Num : " << ct++ <<" ,Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"<<setprecision(2)  <<pl.g << endl;
		}
		
	}





	finout.close();



	return 0;
}