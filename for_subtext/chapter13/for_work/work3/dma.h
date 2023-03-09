#ifndef __DMA_H__
#define __DMA_H__

#include <iostream>
using namespace std;


class ABC{
public:
	ABC(){};
	virtual ~ABC(){};
	virtual void View()const=0;


};

class baseDMA:public ABC{
private:
	char *label;
	int rating;
public:
	baseDMA(const char * l="null",int r=0);
	baseDMA(const baseDMA &rs);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend ostream& operator<<(ostream&os,const baseDMA& rs);
	virtual void View()const;
};



class lacksDMA:public baseDMA{	//派生类不开辟新空间
private:
	enum {COL_LEN=40};
	char color[COL_LEN];
public:
	lacksDMA(const char *l="null",int r=0,const char* c="blank");
	lacksDMA(const baseDMA& rs,const char* c="blank");
	virtual ~lacksDMA(){}
	friend ostream& operator<<(ostream&os,const lacksDMA& rs);
	virtual void View()const;
};


class hasDMA:public baseDMA{	//派生类开辟新空间 
private:
	char * style;
public:
	hasDMA(const char *l="null",int r=0,const char *s="null");
	hasDMA(const baseDMA& ba,const char *s);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	friend ostream& operator<<(ostream&os,const hasDMA& hs);
	virtual void View()const;




};




#endif
