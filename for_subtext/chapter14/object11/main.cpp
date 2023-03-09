//非模版函数作为友元函数

#include <iostream>

using namespace std;

template<class T>
class HasFriend			
{
private:
	T item;
	static int ct; //相同的类，共用一个ct //要单独初始化
public:
	HasFriend(const T &i):item(i){ct++;}
	~HasFriend(){ct--;}

	friend void counts(); //显示ct的值 //所有HasFriend 的友元 such as: HasFriend<int>,HasFriend<double>

	friend void Reports(HasFriend<T> &hf); //显示类对象 现实item
};


template<class T>
int HasFriend<T>::ct=0; //类模版t的静态变量初始化，重要啊...
						//所有的一种类型共用一个ct值 
						//HasFriend<int> 共用一个ct值 该ct值+1之后，所有的 HasFriend<int> ct值+1
						//其他的 类型 比如HasFriend<double> 不会+1 还是模版的初始值 



void counts(){
	cout<<"------------"<< endl;
	cout << "int count:" <<HasFriend<int>::ct ;		//两个ct值其实是不一样的
	cout << " , double count:" <<HasFriend<double>::ct <<endl;
}


void Reports(HasFriend<int> &hf){	 //显示所有 HasFriend<int> 类的值
	cout << "HasFriend<int> :"<<hf.item << endl;
}

void Reports(HasFriend<double> &hf){	//显示所有 HasFriend<double> 类的值
	cout << "HasFriend<double> :"<<hf.item << endl;
}




int main(){
	cout <<"No object declared:";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared:";
	counts();
	Reports(hfi1); //传递进去一个对象 HasFriend<int>

	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared:";
	counts();
	Reports(hfi2); //传递进去一个对象 HasFriend<int>

	HasFriend<double> hfd(5.55);
	cout << "After hdf declared:";
	counts();
	Reports(hfd); //传递进去一个对象 HasFriend<int>

	return 0;
}


