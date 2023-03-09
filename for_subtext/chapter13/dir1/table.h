#ifndef __TABTENNO_H__
#define __TABTENNO_H__

#include <iostream>
#include <string>
using namespace std;

class TableTennisPlayer{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string &fn="None",const string &ln="None",bool hs=false);
	void Name()const;
	bool hastable()const{return hasTable;}
	void ResetTable(bool v){hasTable=v;}
};

#endif