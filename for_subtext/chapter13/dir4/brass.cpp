#include "brass.h"
#include <cstring>

Brass::Brass(const char *fullname,long accnum,double amount):accnum_(accnum),
	amount_(amount){
		int n=strlen(fullname);
		fullname_=new char[n+1];
		strcpy(fullname_,fullname);	
		fullname_[n]='\0';
}

Brass::Brass(const Brass& br){
		int n=strlen(br.fullname_);
		fullname_=new char[n+1];
		strcpy(fullname_,br.fullname_);
		accnum_=br.accnum_;
		amount_=br.amount_;
}

Brass::~Brass(){
	delete []fullname_;
}


bool Brass::save(double amt){
	if(amt <0){
		cout <<"存款必须大于0,存款失败"<< endl;
		return false;
	}
	else{
		amount_ +=amt;
		cout <<"存款成功,存入金额:" << amt << endl;
		return true;
	}
}

bool Brass::withdraw(double amt){
	if(amt > amount_){
		cout <<"取款超出金额,取款失败,当前余额 ："<< get_amount() <<". "<< endl;
		return false;
	}
	else{
		amount_ -=amt;
		return true;
	}
}

void Brass::changename(const char * new_name){
	delete []fullname_;
	fullname_=new char[strlen(new_name)+1];
	strcpy(fullname_,new_name);

}

void Brass::show(){
	cout <<"姓名 : " << fullname_ << endl;
	cout <<"账号 : " << accnum_  << endl;
	cout <<"余额 : " << amount_  <<endl;
}

BrassPlus::BrassPlus(const char* fullname,const char* alias,
	long accnum,double amount,double limit,
	double rate,double debt):Brass(fullname,accnum,amount),limit_(limit),rate_(rate),debt_(debt){
	int n=strlen(alias);
	alias_=new char[n+1];
	strcpy(alias_,alias);
}

BrassPlus::BrassPlus(const Brass &br,const char *alias,double limit,double rate,double debt):Brass(br),limit_(limit),rate_(rate),debt_(debt){
	
	int n=strlen(alias);
	alias_=new char[n+1];
	strcpy(alias_,alias);
}

BrassPlus::~BrassPlus(){
	delete []alias_;
} 

void BrassPlus::changealias(const char* new_alias){
	delete []alias_;
	alias_=new char[strlen(new_alias) +1];
	strcpy(alias_,new_alias);

}


bool BrassPlus::withdraw(double amt){
	double temp=get_amount();
	if(amt <= temp){
		return Brass::withdraw(amt);

	}else if(amt <= temp + limit_ - debt_){
		double differ=amt -temp;
		save(differ);
		Brass::withdraw(amt);
		debt_= differ * (1+rate_);

		return true;
	}else{
		cout <<"超出上限,取款失败" << endl;
		return false;
	}

	
}



void BrassPlus::show(){
	Brass::show();
	cout <<"别名 : " <<	alias_ << endl;
	cout <<"额度 : " << limit_  << endl;
	cout <<"利率 : " << rate_  <<endl;
	cout <<"欠款 : " << debt_  <<endl;
}











