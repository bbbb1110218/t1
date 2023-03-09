#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool insert(stringstream& s,string& str);

int main(){

	stringstream str;
	char temp[20];

	string temp("1 2 &53 -4 5 6");
	string temp2("hello kiff44,54 54");
	
	insert(str,temp);		//注入两个字符串
	insert(str,temp2);		//注入两个字符串
	int n;
	long total=0;
	while(str >>n ) {
		cout << n  << endl;
		total +=n;

	}
	

	cout <<"Total value = " << total << endl;

	return 0;

}


	//通过修改注入的值
bool insert(stringstream& s,string& str){
	auto p=str.begin();

	for(;p<str.end();p++){
		if(isdigit(*p)  ||   *p=='-'){
			s << *p;
		}else{
			s << " ";
		}
	}
	return true;

}