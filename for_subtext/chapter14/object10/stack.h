#ifndef __STACK__H__
#define __STACK__H__
#include <iostream>



template<typename T>
class Stack{
private:
	static const int MAX=10;
	T items[MAX];
	int top;
public:
	Stack();
	bool isfull();
	bool isempty();
	bool push(T& item);
	bool pop(T& item);
	void show()const;
};


template<typename T>
Stack<T>::Stack(){
	top=0;
}

template<typename T>
bool Stack<T>::isfull(){
	return top==MAX;
}

template<typename T>
bool Stack<T>::isempty(){
	return top==0;
}

template<typename T>
bool Stack<T>::push(T& item){
	if(!isfull()){
		items[top++]=item;
		return true;
	}else
		return false;
}


template<typename T>
bool Stack<T>::pop(T& item){
	if(!isempty()){
		item=items[--top];
		return true;
	}else
		return false;
}


template<typename T>
void Stack<T>::show()const{
	std::cout<<"Stack:[";
	for(int i;i<top;i++){
		std::cout << items[i] << " ";
	}
	std::cout << "]"<< std::endl;
}


#endif




