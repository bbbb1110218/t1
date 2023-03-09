#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using namespace std;


template<class Item>
class Queue{
private:
	enum{Q_SIZE=10};

	class Note{
	public:
		Item item;
		Note * next;
		Note(const Item &t):item(t),next(NULL){}
	};

	Node * front;		//队列首
	Node * rear;		//队列尾
	int items;
	const int qsize;  //最大的排队数量
public:

	Queue(int qs=Q_SIZE);//初始化一个队列
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Item &item);  //入队列
	bool dequeue(Item &item);		// 出队列			


};



template<class Item>
Queue<Item>::Queue(int qs):queue_max(qs){
	front=rear=nullptr;
	items=0;
}

template<class Item>
Queue<Item>::~Queue(){
	Node *temp;
	while(front !=nullptr){
		temp=front;
		front=front->next;
		delete temp;
	}
}

template<class Item>
bool Queue<Item>::isfull()const{
	return items==queue_max;
}


template<class Item>
bool Queue<Item>::isempty()const{
	return items==0;
}

template<class Item>
int Queue<Item>::queuecount()const{
	return items;
}


template<class Item>
bool Queue<Item>::enqueue(const Item& it){
	if(isfull()){
		cout <<"Queue is full" << endl;
		return false;
	}
	
	Node *temp=new Node(it);  //Node 是一个类
	temp->item=it;
	temp->next=nullptr;

	if(front==nullptr)
		front=temp;
	else
		rear->next=temp;
	rear=temp;
	items++;
	return true;
}

template<class Item>
bool Queue<Item>::dequeue(Item &it){
	if(isempty()){
		cout <<"Queue is isempty" << endl;
		return false;
	}
	it =front->item;
	Node * temp=front;
	front=front->next;
	delete temp;
	items--;
	return true;
}

// ostream& operator<<(ostream &os,Queue& q){
// 	Queue::Node* temp=q.front;
// 	os <<"[ ";
// 	while(temp !=nullptr){
// 		os <<temp->item.get_arrive_time() <<", ";
// 		temp=temp->next;
// 	}
// 	os <<"]"<<std::endl;

// 	return os;
// }








#endif
