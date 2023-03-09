#include "cd.h"

class Classic :public Cd{
private:
	char *song;
public:
	Classic(const char *s1="None",const char *s2="None", const char *sons="None",int n=0,double x=0.0);
	Classic(const Cd &c,const char *sons);
	Classic(const Classic&c);
	Classic& operator=(const Classic&c);  //写到这里值·
	virtual void Report()const;
	virtual ~Classic();
};