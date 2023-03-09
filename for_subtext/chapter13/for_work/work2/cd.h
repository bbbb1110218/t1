#ifndef __CD_H__
#define __CD_H__

#include <iostream>
using namespace std;

class Cd{
private:
	char *performers;
	char *label;
	int selecions;
	double playtime;
public:
	Cd(const char *s1="None",const char *s2="None",int n=0,double x=0.0);
	Cd(const Cd &c);
	virtual ~Cd();
	Cd& operator=(const Cd&c);
	virtual void Report()const;  //show all data
	

};
#endif
