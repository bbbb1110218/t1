#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using namespace std;

class Customer{ 
private:
	long arrive;	  //开始操作Atm机的时间
	int processtime;  //操作时间
public:
	Customer(){arrive=processtime=0;};
	void set(long when);
	long when()const {return arrive;};
	int ptime()const {return processtime;}

}

typedef Customer Item;


class Queue{
private:
	enum{Q_SIZE=10};
	struct Node{
		Item item;
		struct Node * next;
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


#endif