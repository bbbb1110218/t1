#include "table.h"


TableTennisPlayer::TableTennisPlayer(const string &fn,const string &ln,bool hs):firstname(fn),lastname(ln),hasTable(hs){

}

void TableTennisPlayer::Name()const{
	cout << firstname <<", " <<lastname;
}
