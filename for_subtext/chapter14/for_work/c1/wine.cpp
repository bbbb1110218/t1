#include "wine.h"

Wine::Wine(const char *l,int y,const int year[],const int bot[]):label(l),iYear(y),info(Arrayint(year,y),Arrayint(bot,y)){

}

Wine::Wine(const char *l,int y):label(l),iYear(y),info(Arrayint(y), Arrayint(y)){

}

void Wine::Getbotts(){
    cout <<"Enter " << iYear <<"kind of the wine:\n";
    for(int i=0;i<iYear;i++){
        cout <<"please enter kind#" << i+1 <<"wine years:"<< endl;
        cin >> info.first()[i];
        cout <<"please enter kind#" << i+1 <<"wine bottles:"<< endl;
        cin >> info.second()[i];


    }
    while(cin.get() !='\n');

//	cout <<"Years:[";
//	for(int i=0;i<iYear;i++){
//		cout << info.first()[i] << ",";
//	}
//	cout << "]\n";

}

const string &Wine::Label() const {
    return label;
}

int Wine::Sum()const{

    return info.second().sum();  //valarray 有一个方法类 sum 求和

}

void Wine::Show() const {
    cout << "-------------\n";
    cout << "| Wine Name:"<<Label() <<"\n";
    cout << "| Years    bottles:\n";
    for(int i=0;i<iYear;i++){
        cout <<"| " << info.first()[i] <<"        " << info.second()[i] <<"\n";
    }
    cout << "-------------\n";


}


