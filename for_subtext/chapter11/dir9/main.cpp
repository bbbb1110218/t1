#include "stonewt.h"


const int SIZE=6;



int main(){
	Stonewt arr[SIZE]={Stonewt(13,5),
					  Stonewt(13,3),
					  Stonewt(1,12)};

	double temp_double;

	Stonewt comp=Stonewt(11,0.0);
	Stonewt max;
	Stonewt min;
	max=min=arr[0];

	unsigned int count=0;

	cout <<"Fill 3-6 ."<<endl;

	for(int i=3;i<SIZE;i++){
		cout <<"Please enter element NO. #"<< i+1 <<":";
		cin >> temp_double;
		arr[i]=Stonewt(temp_double);
	}

	for(int i=0;i<SIZE;i++){
		arr[i].set_type(Stonewt::POUNDS);
		max=(max > arr[i]) ? max : arr[i];
		min=(min < arr[i]) ? min : arr[i];
		if(arr[i] > comp)
			count++;
	}

	cout <<"max:" << max<<endl;
	cout <<"min:" << min<<endl;
	cout <<"heavier then 11Stone counts:" <<count << endl;



	return 0;

}