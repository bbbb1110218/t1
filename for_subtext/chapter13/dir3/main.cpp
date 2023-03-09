#include "brass.h"

int main(){
	Brass Rick("Rick",123456,4000.00);
	BrassPlus Jack("Jack",654321,3000.00);


	Rick.ViewAcct();
	cout << endl;
	Jack.ViewAcct();
	cout << endl;
	cout <<"Jack 账户 存入 $1000"<< endl;
	Jack.Deposit(1000);
	cout << endl;
	Rick.Withdraw(4100);

	cout << endl;

	Jack.Withdraw(4100);

	cout << endl;

	Rick.ViewAcct();
	cout << endl;
	Jack.ViewAcct();
	cout << endl;



	

	return 0;
}