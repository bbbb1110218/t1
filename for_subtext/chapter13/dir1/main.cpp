#include "table.h"
#include <iostream>


int main(){
	using std::cout;

	TableTennisPlayer player1("min","liang",false);
	TableTennisPlayer player2("min","rui",true);
	player1.Name();
	if(player1.hastable()){
		cout << ":has a table\n";
	}else{
		cout <<":hasn't a table\n";
	}

	player2.Name();
	if(player2.hastable()){
		cout << ":has a table\n";
	}else{
		cout <<":hasn't a table\n";
	}

	return 0;

}