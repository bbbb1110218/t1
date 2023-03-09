#include <iostream>
#include <fstream>
using namespace std;

struct pl{
	char name[20];
	char xingbie[20];
	int age;
	double feet;
};

int main(){
	pl min;
	pl* pointer =&min;
	strcpy(min.name,"rui");
	strcpy(min.xingbie,"man");
	min.age=23;
	min.feet=34.5;
	

	ofstream fout;
	fout.open("d.dat",ios_base::out | ios_base::trunc | ios_base::binary);

	if(!fout.is_open()){
		cout <<"can't open the file" << endl;
		return -1;
	}

	fout.write((char *)&min,sizeof(pl));
	fout.close();



   
	return 0;
}

/*

struct pl{
	char name[20];
	int age;
	double feet;
};

pl min;
pl* pointer =&min;
strcpy(min.name,"minliang");
min.age=23;
min.feet=34.5;

fout.write((char *)&min,sizeof(pl));
//需要类型转换，转换成 字节形式的指针
fout.close();



*/