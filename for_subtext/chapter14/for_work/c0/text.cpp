#include <iostream>
using namespace std;

int main(){
	string arr[]={"hello,kitty","hello ,world"};
	int arr2[]={3,5,6};

	for(auto &&i:arr2)
		i +=3;

	for(auto i:arr2)
		cout << i << endl;
	return 0;
}