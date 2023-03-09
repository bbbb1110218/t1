
#ifndef __DIR3_TIME_H__
#define __DIR3_TIME_H__

#include <iostream>
using namespace std;




class Time{
	private:
		int Hours;
  	int Mintues;
    void ret_set();  //超过时间重置
  public:
    Time();
    Time(int h,int m);
    void show();
    Time operator*(double n);

    Time& operator<<(const char *str);
    friend Time operator*(double n,Time &t);
    friend ostream& operator<<(ostream& os,Time &t);

    
};

#endif