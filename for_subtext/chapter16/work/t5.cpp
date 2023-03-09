#include<iostream>
#include<string>
#include<algorithm>

using namespace  std;

template<class T>
int arrCount(T* arr,int n){
    sort(arr,arr+n);
    T* p=unique(arr,arr+n);
    return p-arr;
}


template<class T>
void print(T value){cout << value << endl;}

int arr[15]={1};

int main(){

	string arr[10]={"hello","kitty","fuck","you","i2","love","i","you","you","minliang"};
	//int size=;
	for_each(arr,arr+arrCount(arr,10),print<string>);
	cout << "newline---\n";

	int ai[5]={1,2,3,2,1};
	for_each(ai,ai+arrCount(ai,5),print<int>);






   


    return 0;
}