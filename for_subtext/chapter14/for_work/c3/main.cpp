#include <iostream>
#include "myhead.h"
using namespace std;

int main(){

	BadDude min("min","liang",34);

	min.Person::show();
	min.PokerPlayer::show();
	min.Gunslineger::show();
	min.show();




	return 0;
}