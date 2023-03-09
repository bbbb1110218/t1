#include <iostream>
#include <ctime>
#include <cstring>


using namespace std;

template <class T,int size>
class Stack{
private:
	int top;
	T arr[size];
public:
	Stack(){top=0;}
	bool isfull(){return top==size;}
	bool isempty(){return top==0;}
	bool push(const T&t){
		if(isfull()){
			cout <<"Stack full" << endl;
			return false;
		}
		arr[top++]=t;
		return true;

	}	bool pop(T &t){
		if(isempty()){
			cout <<"Stack empty" << endl;
			return false;
		}
		t=arr[--top];
		return true;

	}
	

};



int main(){
	string arr[4]={"hello,kitty",
					"hello,world",
					"hello,temlp3",
					"hello,temp4"};
	Stack<string,3> tt;
	for(auto & i:arr){
		tt.push(i);
	}

	string temp;
	for(int i=0;i<4;i++){
		tt.pop(temp);
		cout << temp << "be poped " << endl; 
	}




	return 0;
}
