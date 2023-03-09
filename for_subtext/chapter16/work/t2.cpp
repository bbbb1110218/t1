#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void ToLow(string &str){
	string result;

	for(int i=0;i<str.size();i++){
		if(isalpha(str[i]))
			result +=tolower(str[i]);
	}

	str=result;
	

}

bool judge(string str){
	cout <<"string addr = " << &str << endl;
	if(str.size() < 2)
		return false;
	auto start=str.begin();
	auto end =str.end()-1;
	for(;start<end;start++,end--){
		if(*start != *end)
			return false;
	}
	return true;
}




int main(){
	string temp;

	cout << "请输入一个字符判断是不是回文 quit 退出:";

	while(getline(cin,temp) && temp !="quit"){
		ToLow(temp);
		

		if(judge(temp))
			cout << temp << "是回文" << endl;
		else
			cout << temp << "不是回文" << endl;

		cout << "请输入下一个字符:";


	}

	return 0;


}
