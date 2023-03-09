#include "brassabc.h"

void Braabc::withdraw(double amt){

	amount_ -=amt;
}


void Brass::show()const{
	cout <<"姓名:"<< Fullname() << endl;
	cout <<"账号:"<<	Accnum() << endl;
	cout <<"金额:" << Amount() << endl;
	cout << endl;
}

void Brass::withdraw(double amt){
	if(amt <0){
		cout <<"withdraw can't be negative[取款小0]" << endl;
	}else if(amt > Amount()){
		cout << "Excess of deposit amount[超出取款金额]" <<endl;
	}else{
		Braabc::withdraw(amt);
	}
}

BrassPlus::BrassPlus(const string &fullname,long accnum,double amount,double topmax,
	double rate,double loans):Braabc(fullname,accnum,amount),topmax_(topmax),
	rate_(rate),loans_(loans){}


void BrassPlus::withdraw(double amt){
	const double temp=Amount();
	if(amt < temp){
		Braabc::withdraw(amt);
	}else if(amt < temp + topmax_ - loans_){
		double temp2= amt - temp;
		save(temp2);
		Braabc::withdraw(amt);
		loans_= temp2 * (1+rate_);
		cout <<"rate[利息]:" << temp2*rate_ << endl;
	}else{
		cout << "Excess of deposit amount[超出贷款金额]" <<endl;
	}
}

void BrassPlus::refund(){
	const double n = Amount();  //当前余额
	if(n > 0 && loans_ >0){
		if(n >= loans_){
			cout <<"已经还贷款 :$ " << loans_ <<" ,贷款已经还清。" << endl;

			Braabc::withdraw(loans_);
			ChangeLoads(loans_);
			
		}else{
			Braabc::withdraw(n);
			ChangeLoads(n);
			cout <<"已经还贷款 :$ " << n << ",还有贷款 :$" << loans_ << "无力偿还." << endl;

		}
	}
}


void BrassPlus::show()const{
	cout <<"姓名   : "<< Fullname() << endl;
	cout <<"账号   : "<<	Accnum() << endl;
	cout <<"金额   : " << Amount() << endl;
	cout <<"贷款额度:" << topmax_ << endl;
	cout <<"利率.  :" << rate_ << endl;
	cout <<"银行贷款:" <<loans_ << endl;
	cout << endl;
}


void BrassPlus::save(double amt){
	Braabc::save(amt);
	refund();
}

