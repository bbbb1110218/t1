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

	ifstream fin;
	fin.open(filename,ios_base::in | ios_base::binary);

	if(fin.is_open()){
		cout <<"Here are the content of " << filename <<  endl;
		while(fin.read((char *)&pl,sizeof(pl) )){
			cout <<"Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"<<setprecision(2)  <<pl.g << endl;
		}
		fin.close();
	}

	ofstream fout;
	fout.open(filename,ios_base::out |ios_base::app |ios_base::binary);
	if(!fout.is_open()){
		cout << "Can't open file "<< filename << endl;
		exit(0);

	}

	cout << "Enter plant name(enter blank line to quit)" <<endl;

	cin.get(pl.name,20);
	while(pl.name[0] !='\0'){

		while(cin.get() !='\n');
		cout <<"Enter the planet population:";
		cin >>pl.population;
		cout << "Enter the planet g:";
		cin >> pl.g; 
		while(cin.get() !='\n');
		fout.write((char *)&pl,sizeof(pl));

		cout << "Enter plant name(enter blank line to quit)" <<endl;
		cin.get(pl.name,20);
	}

	fout.close();

	fin.close();

	fin.open(filename,ios_base::in | ios_base::binary);

	if(fin.is_open()){
		cout <<"Here are the content of " << filename <<  endl;
		while(fin.read((char *)&pl,sizeof(pl) )){
			cout <<"Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"<<setprecision(2)  <<pl.g << endl;
		}
		fin.close();
	}


	return 0;
}