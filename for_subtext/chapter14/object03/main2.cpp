#include "student2.h"

const int SIZE=3;
const int MA=5;


void fill(Student &st,int n);

int main(){

	Student aba[SIZE]={Student(MA),Student(MA),Student(MA)};

	for(int i=0;i<SIZE;i++){
		fill(aba[i],MA);
	}

	for(int i=0;i<SIZE;i++){
		cout << aba[i] << endl;
		cout <<"Average :" << aba[i].Average() << endl;
	}

	return 0;
}

void fill(Student &st,int n){
	cout <<"please enter the fullname:"<< endl;
	getline(cin,st);
	cout <<"please enter the scores list:" << endl;
	for(int i=0;i<n;i++){
		cin >> st[i];
	}
	while(cin.get() !='\n');
}