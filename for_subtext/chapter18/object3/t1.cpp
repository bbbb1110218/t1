#include <iostream>
#include <functional>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){

	
	function<void(void)> gettime=[](){
		static time_t now=clock();
		static int n=0;
		if(n >0){cout << "Now time:"<< setprecision(20)<<double((clock() - now )/(CLOCKS_PER_SEC * 1.0))<< endl;}
		else{cout <<"Start time:::::" << endl;} 
		n++;};
	gettime();

	int x=6,y=7;
	gettime();
	gettime();
	for(int i=0;i< 10000;i++){
		cout << i ;
		gettime();
	}

	
	
	cout <<x << " "<<y <<endl;
	return 0;
}