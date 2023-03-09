#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	const char * name="闵亮";
	
	for(int i=0;i<strlen(name);i++){
		cout << hex <<(int)name[i] << endl;
	}

	cout <<hex << "hello,kitty" << endl;
	return 0;
}