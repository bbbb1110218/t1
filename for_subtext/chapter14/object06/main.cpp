

#include <iostream>
using namespace std;

#include "stack.h"


const int SIZE=4;

int main(){
	const char * arr[SIZE]={"1.hello,kitty","2.hello,kitty",
							"3.hello,kitty","4.hello,kitty"};
	Stack<const char *> s;
	for(int i=0;i<SIZE;i++){
		s.push(arr[i]);
	}
	const char *ar;

	for(int i=0;i<SIZE;i++){
		s.pop(ar);
		cout << ar << endl;
	}

	return 0;
}