#include "queue.h"

Queue::Queue(int qs):queue_max(qs){
	front=rear=nullptr;
	items=0;
}

Queue::~Queue(){
	Node *temp;
	while(front !=nullptr){
		temp=front;
		front=front->next;
		delete temp;
	}
}

bool Queue::isfull()const{
	return items==queue_max;
}

bool Queue::isempty()const{
	return items==0;
}

bool Queue::enqueue(const Item& it){
	if(isfull()){
		cout <<"Queue is full" << endl;
		return false;
	}
	
	Node *temp=new Node;
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

bool Queue::dequeue(Item &it){
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

ostream& operator<<(ostream &os,Queue& q){
	Queue::Node* temp=q.front;
	os <<"[ ";
	while(temp !=nullptr){
		os <<temp->item.get_arrive_time() <<", ";
		temp=temp->next;
	}
	os <<"]"<<std::endl;

	return os;
}

