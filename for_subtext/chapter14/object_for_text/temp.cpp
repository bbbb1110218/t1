#include <iostream>

using namespace std;

//1
template <class T1,class T2>
class A{
public:
	void show();
};

template<class T1,class T2>
void A<T1,T2>::show(){
	cout <<"use general definition|方法1｜我是普通方法" <<endl;
}


//
//如果传递进来的是int,int 类型，要特殊处理；
template<>
class A<int,int>{		 //特殊处理类的声明
public:
	void show();
};


void A<int,int>::show(){ //特殊处理方法
	cout <<"use specialized definition｜方法2｜我是显式具体化" <<endl;
}

//如果传递进来的第二个参数是int 要特殊处理
template<class T1>
class A<T1,int>{
public:
	void show();
};

template<class T1>
void A<T1,int>::show(){
	cout <<"using partcal specialized definition｜方法3｜我属于部分具体化" <<endl;
}



//如果传递进来的第1个参数是int 要特殊处理
template<class T2>
class A<long, T2>{
public:
	void show();
};

template<class T2>
void A<long,T2>::show(){
	cout <<"using partical specialized definition|方法4｜我属于欧部分具体化的第二个参数"<< endl;
}

//显示实例话//让编译器生成类
template class A<double,int>;

int main(){
	A<double ,double> *temp=new A<double,double>;
	temp->show();
	delete temp;
	A<int,int> t2;
	t2.show();
	A<double,int> t3;
	t3.show();
	A<long,char> t4;
	t4.show();
	return 0;
}