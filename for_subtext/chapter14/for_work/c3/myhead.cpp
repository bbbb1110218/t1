#include "myhead.h"
#include <cstdlib>
#include <ctime>



// Card::Card(){
// 	static int temp=2;

// 	srand(time(NULL));

// 	int t=(rand()%13 + 1) + temp++;
// 	count =t;
// }

ostream& operator<<(ostream&os,Card&c){

	os << "纸牌点数是:" << c.count;
	return os;
}

void Person::show()const{
	cout <<"--------------\n";
	cout << "Name:" <<fName << " " <<sName << endl;
}

int Gunslineger::Draw()const{
	srand(time(NULL));
	return rand() %60 +1;
}

void Gunslineger::show()const{
	Person::show();
	cout <<"枪上的划痕:"<<scratch << endl;
	cout <<"拔枪时间:" << Draw() << endl;
}

Card PokerPlayer::Draw()const{
	srand(time(NULL));

	int t=rand()%13 + 1;

	return Card(t);
}


void PokerPlayer::show()const{
	Person::show();
	Card temp=Draw();
	cout <<	temp << endl;
}

void BadDude::show()const{

	Gunslineger::show();
	Card t=PokerPlayer::Draw();
	cout << t << endl;
	
}








