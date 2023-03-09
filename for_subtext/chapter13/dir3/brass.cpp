#include "brass.h"

Brass::Brass(const string &s,long an,double bal){
	fullName=s;
	acctNum=an;
	balance=bal;
}

void Brass::Deposit(double amt){
	if (amt < 0)
		cout <<"Nagative deposit is not allowed"<< endl;
	else
		balance +=amt;
}

void Brass::Withdraw(double amt){
	if(amt <0)
		cout <<"Withdraw Must be positive[取款余额必须为正]"<< endl;

	else if(amt > balance)
		cout << fullName <<" not sufficient funds[余额不足]" << endl;
	else
		balance -=amt;
}

double Brass::Balance()const{
	return balance;
}


void Brass::ViewAcct()const{
	cout <<"fullName : "<< fullName << endl;
	cout <<"acctNum : "<< acctNum << endl;
	cout <<"余额 : $ " << balance <<endl;
}



BrassPlus::BrassPlus(const string&s,long an,double bal,
		double ml,double rate,double ow):Brass(s,an,bal),
	maxLoad(ml),rate_(rate),owesBank(ow){

}

BrassPlus::BrassPlus(const Brass&br,double ml,double rate,double ow
	):Brass(br){
	maxLoad=ml;
	rate_=rate;
	owesBank=ow;
}



void BrassPlus::ViewAcct()const{
	Brass::ViewAcct();	//声明使用基类里面的函数 ⚠️
	cout <<"透支上限 :$ " << maxLoad <<endl;
	cout <<"利率：" << rate_ << endl;
	cout <<"透支总额 :$ " << owesBank << endl;
}


void BrassPlus::Withdraw(double amt){
	double bal=Balance(); // 直接调用基类方法  返回当前余额传递给临时变量⚠️
	if(amt <=bal)
		Brass::Withdraw(amt);
	else if(amt <= bal +maxLoad -owesBank){
		double advance=amt-bal;

		owesBank = advance * ( 1 + rate_) ;

		cout <<"手续费:" << advance * rate_ << endl;
		Deposit(advance);		//使用继承的方法

		Brass::Withdraw(amt);		//已经重写方法了，指定使用基类的方法;

	}else{
		cout <<"Credit limit exceeded![超出取款上线]" << endl;
	}

}




