#include "queue.h"


int main(){
	Queue line;
	Customer temp;
	long number=100;
	while(!line.isfull()){
		temp.set(100*(number++));
		line.enqueue(temp);
	}
	cout <<"finally line=" << line; 

	while(!line.isempty()){
		line.dequeue(temp);
		cout <<"number:[" << temp.get_arrive_time() <<"] dequeue"<< endl;
		cout <<"line=" << line; 
	}

	return 0;
}