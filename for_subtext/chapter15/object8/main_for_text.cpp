#include <iostream>
#include <cstdlib>

using namespace std;


int show(int n);


int main(){
	int val;
	cout << "please enter a number:"; 
	while(cin >>val){ 

	try{
		show(val);
	}
			
	catch(const int a){		//catch 数字
		switch(a){
		case 11:
			cout <<"type 11 error\n";

			break;
		case 12:
			cout <<"type 11 error\n";
			break;
		default:
			cout <<"other error\n";
			break;
		}

	catch(const char * s){		//catch  字符串
		cout << s << endl;
		
	}
		

	}
		cout << "please enter anther number:"; 
	}
	
	return 0;
}




int show(int n){
	if(n==0)
		throw 11;		//抛出数字
	else if(n==1)
		throw 12;
	else if(n==2)
		throw "错了错了 n 不能等于2";

	cout << "answer is:" << n+1 << endl;
	return n+1;

}