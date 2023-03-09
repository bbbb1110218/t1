#include <iostream>
#include "sales.h"


using namespace std;










int main(){

	double vals1[12];
	double vals2[12];

	for(int i=0;i<12;i++){
		vals1[i]=i*10 +1 +2000;
		vals2[i]=i*10 +1 +2320; 
	}

	Sales sale1(2013,vals1,12);

	LabelSale sale2("Big watermalen ",2022,vals2,12);

	try{

		// show sale 1
		cout <<"Year:" << sale1.Year() << "\n";
		for(int i=0;i<12;i++){  // 12超出范围,会抛异常
			cout << sale1[i] << " ";
			if(i % 6 ==5)
				cout << endl;
		}

		// show sale 2
		cout <<"Year:" << sale2.Year() << " "<<sale2.Label() <<"\n";
	

		for(int i=0;i<12;i++){  //15超出范围,会抛异常
			cout << sale2[i] << " ";
			if(i % 6 ==5)
				cout << endl;
		}

		
		
	}

										//异常类的排列 应该这样排列
										// 派生类的派生类 ->> 派生类 ->> 基类;
	catch(LabelSale::nBad_index & bad){	//类里面的异常,要加上作用域
		cout << "ERROR Bad info  :"<<bad.what() << endl;
		cout << "ERROR Bad value :"<<bad.LableValue() << endl;
		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
	}


	catch(Sales::Bad_index & bad){ //类里面的异常 要加上作用域
		cout << "ERROR Bad info  :"<<bad.what() << endl;
		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
		cout << bad.what() << endl;

	}



	catch(logic_error & bad){

		cout <<bad.what() << endl;
	}


	try{
		sale2[2]=40;
		sale1[15]=60; //try 会让下面的 catch 捕获
	}


	catch(exception & bad){  //会截获所有异常,所有异常excption 派生出来的
		cout << "in exception " << endl;
		cout << bad.what() << endl;
	}



	catch(LabelSale::nBad_index & bad){	//类里面的异常,要加上作用域
		cout << "ERROR Bad info  :"<<bad.what() << endl;
		cout << "ERROR Bad value :"<<bad.LableValue() << endl;
		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
	}


	catch(Sales::Bad_index & bad){ //类里面的异常 要加上作用域
		cout << "ERROR Bad info  :"<<bad.what() << endl;
		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
		cout << bad.what() << endl;

	}

	


	cout <<"Bye" << endl;


	return 0;
}