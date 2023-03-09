#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	char ch;
	while(cin.get(ch)){
		if(ch !='#')
			cout << ch;
		else{
			cin.putback(ch); //#放回输入缓冲区
			break;
		}


	}
	cout << endl;

	if(!cin.eof()){
		cin.get(ch);
		cout << "Now ch is :" << ch << endl;
	}else{
		cout << "End of input reached" << endl;
		exit(0);
	}

	while(cin.peek() !='#'){
		cin.get(ch);
		cout << ch;

	}
	cout << endl;


	return 0;

}