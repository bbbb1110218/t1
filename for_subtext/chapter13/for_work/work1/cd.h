#ifndef __CD_H__
#define __CD_H__

#include <iostream>
using namespace std;

class Cd{
private:
	char performers[50];
	char label[20];
	int selecions;
	double playtime;
public:
	Cd(const char *s1="None",const char *s2="None",int n=0,double x=0.0);
	virtual ~Cd();
	virtual void Report()const;  //show all data
	

};
#endif
