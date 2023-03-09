#include <iostream>
#include <cstring>

using namespace std;


const int SLEN=10;
int main(){
	char name[SLEN];
	char title[SLEN];

	cout << "Enter your name:";
	cin.get(name,SLEN);

	if(cin.peek() != '\n')
		cout << "Sorry,we don't have enough room for "<< name << endl;

	while(cin.get() !='\n');
	cout << "Dear "<< name <<" enter your title"<< endl;
	cin.get(title,SLEN);
	if(cin.peek() != '\n')
		cout << "我们被迫截取你的头衔"<< endl;
	while(cin.get() !='\n');
	cout << "Name:" << name << endl;
	cout << "title:" << title << endl;

	return 0;
}
