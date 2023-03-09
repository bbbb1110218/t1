#include <string>
#include <iostream>

using namespace std;

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
		cout <<"string addr = " << &temp << endl;

		if(judge(temp))
			cout << temp << "是回文" << endl;
		else
			cout << temp << "不是回文" << endl;

		cout << "请输入下一个字符:";
	}
	return 0;
}



