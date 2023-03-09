#include "dma.h"

const int SIZE=3;
enum COLOR{baseDMA=0,lacksDMA,hasDMA};


int main(){
	ABC *arr[SIZE];
	char t_label[40];
	int t_rating;
	int choice;

	for(int i=0;i<SIZE;i++){
		cout <<"第 #" <<i+1<< "个."<<endl;
		cout << "Please enter the label: ";
		//cin >> t_label;
		//cin.get(t_label,40);
		cin.getline(t_label,40);
		cout <<"Please enter the rating:";
		cin >> t_rating;
		//cin.get();  //rstrip ‘\n’

		cout <<"Please select a storage type: 0 for baseDMA ,1 for lacksDMA,2 for hasDMA\n";
		while((cin >>choice)&&(choice !=0 && choice !=1 && choice !=2)){
			cout <<"Choice Error,Please retry:";
		}
		cin.get();
		switch(choice){
		case baseDMA:
			arr[i]=new class baseDMA(t_label,t_rating);
			break;
		case lacksDMA:
			
			cout <<"Please enter the color:";
			char t_color[40];
			cin.get(t_color,40);
			t_color[40-1]='\0';
			while(cin.get() !='\n'); //注意
			arr[i]=new class lacksDMA(t_label,t_rating,t_color);
			break;
		case hasDMA:
			cout <<"Please enter the style:";
			char t_style[40];
			cin.get(t_style,40);
			t_style[40-1]='\0';
			while(cin.get() !='\n'); //注意
			arr[i]=new class lacksDMA(t_label,t_rating,t_style);
			break;

		}




	}

	for(int i=0;i<SIZE;i++){
		arr[i]->View();
	}

	for(int i=0;i<SIZE;i++){
		delete arr[i];
	}

// ---------
	// hasDMA map("keys",5,"mercator");
	// hasDMA map2(map,"NEW");
	// cout << map2;


	return 0;
}