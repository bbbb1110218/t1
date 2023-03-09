#include "time.h"

using namespace std;


Time::Time(){
    Hours=0;
    Mintues=0;

};

void Time::show(){

    cout <<"Hours:" << Hours <<",Mintues:" << Mintues<< endl;
};

Time::Time(int h,int m){
    Hours=h;
    Mintues=m;
    if(Mintues >=60){
        ret_set();
    }

};

Time Time::operator*(double n){
    Time Temp;
    Temp.Hours = Hours *n;
    Temp.Mintues =Mintues *n;
    Temp.ret_set();
    return Temp;
};


Time& Time::operator<<(const char *str){
    cout <<"[" << str <<"]\n";
    return *this;
}

Time operator*(double n,Time &t){

    cout <<"I am in friend function"<< endl;
    Time Temp;
    Temp.Hours = t.Hours *n;
    Temp.Mintues = t.Mintues *n;
    Temp.ret_set();
    return Temp;
}

 void Time::ret_set(){
    Hours = Hours + Mintues/60;
    Mintues %=60;

 };


ostream& operator<<(ostream& os,Time &t){
   os <<" ["<<t.Hours <<":"<< t.Mintues <<"]\n";
   return os;
 }







