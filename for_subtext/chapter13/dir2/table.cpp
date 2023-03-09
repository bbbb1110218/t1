#include "table.h"


TennisPlayer::TennisPlayer(const string&fn,
	const string &ln,bool b):firstname(fn),lastname(ln),hasTable(b){

}



// TennisPlayer::TennisPlayer(const TennisPlayer &te){

// 	std::cout << "[使用了复制构造函数]\n";
// 	firstname=te.firstname;
// 	lastname=te.lastname;
// 	hasTable=te.hasTable;
// }

void TennisPlayer::Name()const{
	std::cout << firstname <<" " <<lastname;

}


void TennisPlayer::ResetName(const string &fn,const string &ln){
	firstname=fn;
	lastname=ln;
}



RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
	const string &ln,bool b):TennisPlayer(fn,ln,b){
	rating=r;
}

RatedPlayer::RatedPlayer(unsigned int r,
	const TennisPlayer&te):TennisPlayer(te){
	rating=r;
}

RatedPlayer::RatedPlayer(const TennisPlayer&te ,
	unsigned int r):TennisPlayer(te){
	rating=r;
}

std::ostream& operator<<(std::ostream &os,const RatedPlayer&rp){
	os << rp.getName() << " ,Rating:" << rp.getRating() ;
	return os;

}
