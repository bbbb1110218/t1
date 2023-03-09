#include <iostream>
#include "brass.h"
using namespace std;

const int SIZE=3;

int main(){
	Brass *arr[SIZE];
	char temp_name[20];
	char temp_alias[20];
	long temp_acc;
	double temp_amount;//余额
	int choice;


	for(int i=0;i<SIZE;i++){
		cout <<"Please enter #" << i+1 << " 号客户姓名:";
		cin.getline(temp_name,20);
		cout << "Please eenter 客户:[" << temp_name <<"]账号:";
		cin >> temp_acc;
		cout <<"Please eenter 客户:[" << temp_name <<"]初始金额:";
		cin >> temp_amount;

		cout <<"请选择账户类型，有额度(1)没有额度(2)\n";
		
		while(cin >> choice && (choice  !=1 && choice !=2))
			cout <<"账户类型错误请重新输入" << endl;

		
		if(choice ==1){
			arr[i]=new Brass(temp_name,temp_acc,temp_amount);
		}
		
		else if(choice ==2){
			while(cin.get() !='\n');
			double tlimit,trate;
			char talias[20];
			cout <<"请输入账户别名:";
			cin.getline(talias,20);
			cout <<"请输入账户额度:";
			cin >> tlimit;
			cout <<"请输入账户利率:";
			cin >> trate;
			arr[i]=new BrassPlus(temp_name,talias,temp_acc,temp_amount,tlimit,trate,0.0);
		}
		while(cin.get() !='\n');
	}

		

	for(int i=0;i<SIZE;i++){
		arr[i]->show();
		cout <<"\n";
	}

	for(int i=0;i<SIZE;i++){
		delete arr[i];
	}



	return 0;
}