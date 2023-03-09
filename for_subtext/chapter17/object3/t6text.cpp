#include <iostream>
#include <fstream>
using namespace std;


const char * file="planet.dat";

struct CharS{
	char n1:1;
	char n2:1;
	char n3:1;
	char n4:1;
	char n5:1;
	char n6:1;
	char n7:1;
	char n8:1;
	void show(){
		string temp;
		if(n8) temp+="1";else temp+="0";
		if(n7) temp+="1";else temp+="0";
		if(n6) temp+="1";else temp+="0";
		if(n5) temp+="1";else temp+="0";
		if(n4) temp+="1";else temp+="0";
		if(n3) temp+="1";else temp+="0";
		if(n2) temp+="1";else temp+="0";
		if(n1) temp+="1";else temp+="0";
		cout << temp;

	}
};

void Show(CharS & d);

int main(){

	fstream fp(file,ios_base::in|ios_base::out|ios_base::binary);


	if(!fp.is_open()){
		cout << "Can't open " << file  << endl;
		return -1;
	}

	CharS data;
	int count =0;
	while(fp.read((char *)&data,sizeof(CharS))){
		count++;
		data.show();
		// cout << " ";
		// if(count %4 ==3)
		// 	cout << " ";
		// if(count % 8 ==7  || count ==7)
		// 	cout << "\n";

	}

	cout <<"File:" << count <<"bytes" << endl;







	return 0;


}


void Show(CharS & d){
	if(d.n8)
		cout << "1";
	else
		cout << "0";
	if(d.n7)
		cout << "1";
	else
		cout << "0";
	if(d.n6)
		cout << "1";
	else
		cout << "0";
	if(d.n5)
		cout << "1";
	else
		cout << "0";
	if(d.n4)
		cout << "1";
	else
		cout << "0";

	if(d.n3)
		cout << "1";
	else
		cout << "0";
	if(d.n2)
		cout << "1";
	else
		cout << "0";
	if(d.n1)
		cout << "1";
	else
		cout << "0";

}

