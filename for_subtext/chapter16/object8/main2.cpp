#include <iostream>
#include <ctime>
#include <cstdlib>
#include <valarray>


using namespace std;

typedef valarray<int> vint;

void Show(const vint& v,int col);




const int SIZE=12;


int main(){
	vint valint(SIZE);

	int i;

	for(i=0;i<SIZE;i++){
		valint[i]=rand() % 10;
	}

	cout <<"original array:" << endl;
	Show(valint,3);

	valint[slice(0,10,3)]=10;
	Show(valint,3);









	return 0;
}


void Show(const vint& v,int col){
	int lim=v.size();

	for(int i=0;i<lim;i++){
		cout << v[i] ;
		if(i % col ==col-1){
			cout << endl;
		}
		else
			cout <<" ";
	}
	if(lim % col !=0){
		cout << endl;
	}
}