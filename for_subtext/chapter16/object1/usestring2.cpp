#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class MyString:public string{
public:
	MyString(const char* t):string(t){}
	MyString& Capitalize(char sep=' '){
		auto n= this->size();
		(*this)[0]=toupper((*this)[0]);
		for(int i=0;i<n;i++){				
			if((*this)[i]==sep)
				(*this)[i+1]=toupper((*this)[i+1]);
		}
		(*this)[n]='\0';
		return *this;
	}

	size_t find(const char * ch){  // 
		size_t Result=0;
		auto n=(*this).size();
		auto nChar=strlen(ch);

		if(nChar==1){
			for(int i=0;i<n;i++){
				if((*this)[i]==ch[0])
					return i;
			}
		}


		int find=0;
		int start=0;
		while((*this)[find++] !=ch[0]){
			for(;start<nChar;start++){
				if((*this)[find+start] != ch[start]){
					break;
				}
			}
			if(start==nChar)
				return --find;
			else
				start=0;
			if(find==n)
				return Result;
		};


		return --find;
		



	}

	friend ostream& operator<<(ostream& os,MyString& my){
		os << "秘密:" << my[0] <<"****" << my[my.size()-1] << endl;
		return os;
	}

};


int ChCount(const char * s){
	return strlen(s);
}


int main(){
	MyString t("1hello kitty,fuck you bitch");
	//t=t.Capitalize('k');

	cout << t << endl;

	cout << t.find("ch") << endl;
	cout << t.find("tty") << endl;
	//const char * temp="hellomkitt
	cout << ChCount("h") << endl;

	
	




	return 0;
}