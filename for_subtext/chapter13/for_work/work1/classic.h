#ifndef

#include "cd.h"

class Classic :public Cd{
private:
	char song[50];
public:
	Classic(const char *s1="None",const char *s2="None", const char *sons="None",int n=0,double x=0.0);
	Classic(const Cd &c,const char *sons="None");
	virtual void Report()const;
	virtual ~Classic(){}
};