#ifndef __TABLE_H__
#define __TABLE_H__
#include <iostream>
#include <string>

using std::string;



class TennisPlayer{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TennisPlayer(const string &fn="None",const string &ln="None",bool b=false);
	// TennisPlayer(const TennisPlayer &te);
	void showptr()const{std::cout <<(void *)this <<std::endl;}
	void Name()const;
	string getName()const{return firstname +"," +lastname;}
	bool HasTable()const{return hasTable;}
	void ResetTable(bool b){hasTable=b;}
	void ResetName(const string &fn,const string &ln);

};


class RatedPlayer:public TennisPlayer{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r=0, const string &fn="None",const string &ln="None",bool b=false);
	RatedPlayer(unsigned int r,const TennisPlayer&te);
	RatedPlayer(const TennisPlayer&te,unsigned int r);
	RatedPlayer(const TennisPlayer& te):TennisPlayer(te){rating=0;}
	unsigned int getRating()const{return rating;}
	void setRating(unsigned int r){rating=r;}
	friend std::ostream& operator<<(std::ostream &os,const RatedPlayer&rp);
};

#endif