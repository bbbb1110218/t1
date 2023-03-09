#include "head.h"



int main(){
	Tv sony;
	Remote rem;
	//sony.ChangeBattery(rem);
	rem.SetChannel(sony,1);
	sony.ShowState();

	return 0;
}