#include "text.h"

const int SIZE=3;


int main(){

	Person minqian("minqian",30,"化妆",168.00,45.00);



	BaseABC *arr[SIZE]={new BaseABC("minliang",32),  //指针要开辟新空间啊
						new Person("minrui",3,"奥特曼",120.00,24.00),
						&minqian
						};


	for (int i=0;i<SIZE;i++){
		arr[i]->show();
		cout <<"Addr:" << arr[i] << endl;
		cout <<"sizeof:" << sizeof(*arr[i]) << endl;
	}

	delete arr[0];  // new开辟出来的内存  delete 要记得删除
	delete arr[1];
	//delete arr[2];	//自动变量，不用删除，离开作用域就自动销毁了

	return 0;
}

