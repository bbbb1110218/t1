#include<iostream>

using namespace std;

const int size=3;

int main(){
	int arr[size]={3,5,8};
	int result;
	bool succeed=false;

	cout <<"Guess an number:";
	while(cin >> result){
		for(int i=0;i<size;i++){
			if (arr[i]==result)
			{
				succeed =true;
				break;
			}}
		if(succeed)
				break;
		cout <<"Guess an number:";

	}
	cout <<"Bye"<< endl;



	return 0;

}