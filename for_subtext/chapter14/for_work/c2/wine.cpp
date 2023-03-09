#include "wine.h"

Wine::Wine(const char *l,int y,const int year[],const int bot[]):string(l),iYear(y),PairArray(Arrayint(year,y),Arrayint(bot,y)){

}

Wine::Wine(const char *l,int y):string(l),iYear(y),PairArray(Arrayint(y), Arrayint(y)){

}

void Wine::Getbotts(){
    cout <<"Enter " << iYear <<"kind of the wine:\n";
    for(int i=0;i<iYear;i++){
        cout <<"please enter kind#" << i+1 <<"wine years:"<< endl;
        cin >> PairArray::first()[i];
        cout <<"please enter kind#" << i+1 <<"wine bottles:"<< endl;
        cin >> PairArray::second()[i];


    }
    while(cin.get() !='\n');

//	cout <<"Years:[";
//	for(int i=0;i<iYear;i++){
//		cout << info.first()[i] << ",";
//	}
//	cout << "]\n";

}

const string &Wine::Label() const {
    return (const string &)(*this);
}

int Wine::Sum()const{

    return PairArray::second().sum();  //valarray 有一个方法类 sum 求和

}

void Wine::Show() const {
    cout << "-------------\n";
    cout << "| Wine Name:"<<Label() <<"\n";
    cout << "| Years    bottles:\n";
    for(int i=0;i<iYear;i++){
        cout <<"| " << PairArray::first()[i] <<"        " << PairArray::second()[i] <<"\n";
    }
    cout << "-------------\n";


}


