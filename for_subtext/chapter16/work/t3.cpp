#include<string>
#include<iostream>
#include<cctype>
using namespace std;

void estimate(string &str){
	string temp;
	for(auto p=str.begin();p!=str.end();p++){
		int n=static_cast<int>(*p);
		if((n>64 && n<91) || (n >96 && n<123) )
			temp += *p;
	}
	str=temp;
}

int main(){
	

	string f("***fuck%^&*nifudmal44345(");
	estimate(f);
	cout << f << endl;
	return 0;
}

T