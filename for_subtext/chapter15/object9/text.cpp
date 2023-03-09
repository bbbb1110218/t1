#include <iostream>
using namespace std;

template<class T>
struct Node{
	T data;
	Node<T> *next;
	void show(){std::cout <<"data:"<< data << std::endl;}
};


int main(){
	cout << sizeof(Node<Node<int> >) << endl;
	cout << sizeof(Node<char>) << endl;

	Node<int> *fuck=new Node<int>;
	Node<int> *temp=fuck;
	Node<int> *tt; 

	for(int i=10;i<24;i++){
		fuck->data=i;
		fuck->next=new Node<int>;
		fuck=fuck->next;
	}

	while(temp !=fuck){
		tt=temp;
		temp->show();
		temp=temp->next;
		delete tt;
	}


 	
	return 0;
}