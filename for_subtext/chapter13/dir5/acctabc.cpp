#include "acctabc.h"


Acctabc::Acctabc(const string &s,long an,double bal){
	fullName=s;
	acctNum=an;
	balance=bal;

}

void Acctabc::Deposit(double amt){
	if (amt < 0)
		cout <<"Nagative deposit is not allowed"<< endl;
	else
		balance +=amt;
}


 void Acctabc::Withdraw(double amt){
 		balance -=amt;
 }





void Brass::Withdraw(double amt){
	if(amt <0)
		cout <<"Withdraw Must be positive[取款余额必须为正]"<< endl;

	else if(amt > Balance())
		cout << FullName() <<" not sufficient funds[余额不足]" << endl;
	else
		Acctabc::Withdraw(amt);

}


void Brass::ViewAcct()const{
	cout <<"fullName : "<< FullName() << endl;
	cout <<"acctNum : "<< AcctNum() << endl;
	cout <<"余额 : $ " << Balance() <<endl;
}



BrassPlus::BrassPlus(const string&s,long an,double bal,
		double ml,double rate,double ow):Acctabc(s,an,bal),
	maxLoad(ml),rate_(rate),owesBank(ow){

}

BrassPlus::BrassPlus(const Acctabc &br,double ml,double rate,double ow
	):Acctabc(br){
	maxLoad=ml;
	rate_=rate;
	owesBank=ow;
}



void BrassPlus::ViewAcct()const{
	cout <<"fullName : "<< FullName() << endl;
	cout <<"acctNum : "<< AcctNum() << endl;
	cout <<"余额 : $ " << Balance() <<endl;
	cout <<"透支上限 :$ " << maxLoad <<endl;
	cout <<"利率：" << rate_ << endl;
	cout <<"透支总额 :$ " << owesBank << endl;
}


void BrassPlus::Withdraw(double amt){
	double bal=Balance(); // 直接调用基类方法  返回当前余额传递给临时变量⚠️
	if(amt <= bal)
		Acctabc::Withdraw(amt);
	else if(amt <= bal +maxLoad -owesBank){
		double advance=amt-bal;

		owesBank = advance * ( 1 + rate_) ;

		cout <<"手续费:" << advance * rate_ << endl;
		Deposit(advance);		//使用继承的方法

		Acctabc::Withdraw(amt);		//已经重写方法了，指定使用基类的方法;

	}else{
		cout <<"Credit limit exceeded![超出取款上线]" << endl;
	}

}




