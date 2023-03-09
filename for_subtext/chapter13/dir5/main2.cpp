#include "acctabc.h"


const int N=3;
int main(){


	
	Acctabc *pc[N];
	string temp_name;
	long temp_acc;
	double temp_balance;
	int kind;


	for(int i=0;i<N;i++){
		cout <<"Please enter # " << i+1 <<" Name:";
		getline(cin,temp_name);
		cout <<"Enter client's account number:";
		cin >> temp_acc;
		cout <<"Please enter " << temp_name <<" 存款金额:";
		cin >> temp_balance;
		cout <<"请输入账户类型，不可以透支选择1，可以透支选择2:" << endl;

		while(cin >> kind && (kind !=1 && kind !=2)){
			cout <<"输入错误，请输入1或者2:"<< endl;
		}


		if(kind==1)
			pc[i] =new Brass(temp_name,temp_acc,temp_balance);
		else
		{
			double tmax,trate;
			cout <<"请输入透支额度:";
			cin >> tmax;
			cout <<"请输入利率:";
			cin >> trate;
			pc[i]=new BrassPlus(temp_name,temp_acc,temp_balance,tmax,trate);
		}

		while(cin.get() !='\n');
	}

	cout <<"\n";

	for(int i=0;i<N;i++){
		cout <<"------------\n";
		pc[i]->ViewAcct();
	}

	

	for(int i=0;i<N;i++){
		delete pc[i];

	}




	

	return 0;
}