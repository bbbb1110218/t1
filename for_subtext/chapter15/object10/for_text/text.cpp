#include <iostream>
using namespace std;

int& temp(){
	static int i=0;
	i++;
	return i;
}

int main(){

	while(1){
		static int tt=0;
		tt++;
		if(tt ==20000000)
			break;
		cout << temp() << "  ";
		if(tt % 5 ==4)
			cout << endl;

	}
	
	return 0;
}