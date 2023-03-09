#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using namespace std;


class Customer{
private:
	long arrive;
	int operator_time;
public:
	Customer(){arrive=operator_time=0;};
	Customer(const long &t,const int &ot){arrive=t;operator_time=ot;};
	void set(const long &t){arrive=t;};
	long get_arrive_time(){return arrive;};
	int get_op_time(){return operator_time;};
};

typedef Customer Item;

class Queue{
private:
	enum{defalut_size=10};
	struct Node{
		Item item;
		struct Node *next;
	};
	Node *front;
	Node *rear;
	int items;
	const int queue_max;
public:
	Queue(int qs=defalut_size);
	~Queue();
	int get_max()const{return queue_max;}
	int get_cout()const{return items;}
	bool isfull()const;
	bool isempty()const;
	bool enqueue(const Item &it);
	bool dequeue(Item &it);
	friend ostream& operator<<(ostream &os,Queue& q);

};

#endif