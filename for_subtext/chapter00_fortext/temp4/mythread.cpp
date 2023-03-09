#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void fuck(){
	cout <<"hello,kitty"<< endl;
}

int main(){
	function<void(void)> task;
	task=[](){cout << "i am in task" << endl;};
	

	for(int i=0;i<100;i++){
		thread t1(task);
		thread t2(fuck);
		t1.join();
		t2.join();
	}


	
	return 0;
}