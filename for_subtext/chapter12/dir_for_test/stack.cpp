#include <iostream>

using namespace std;


typedef unsigned long Item;  //定义元素为一种类型

class Stack{
	private:
		Item *pitem;  //栈是一个指针,需要使用的时候进行初始化
		int top;		//栈顶 数量
		int size;		//栈的数量
		static const int count=10; //默认值 也可以用enum{count=10};

	public:

		Stack(int n= count);  //初始化 写在函数原型里面
		Stack(Stack& s);		//复制构造函数
		~Stack(){delete []pitem;}	//释放开辟的内存		

		int gettop()const{return top;}	//返回栈顶
		int getsize()const{return size;}	//返回栈的总元素个数

		bool isempty()const{return top==0;}	//判断栈是否为空
		bool isfull()const{return top==size;}	//判断栈是否满了


		bool push(Item it);		//入栈
		bool pop(Item &it);		//出栈

		
		Stack& operator=(Stack& st);  //赋值运算符

		friend ostream& operator<<(ostream&os,Stack& st);
											//重新载入cout

};

int main(){
	Stack s(20);
	for(int i=0;i<4;i++){
		s.push(i*i +1);
	}
	Stack s1=s;


	cout << "size:"<<s1.getsize() <<",top:" << s1.gettop() << endl;
	cout << s1<< endl;

	Item temp;
	for(int i=0;i<10;i++){
		if (s.pop(temp))
			cout << temp <<" be poped"<< endl;
		else
			s.push(20);
	}


	return 0;
}







Stack::Stack(int n){
	size=n;
	top=0;
	pitem =new Item[size];  //开辟需要的内存空间
}

Stack::Stack(Stack& s){
	size=s.size;
	top=s.top;
	pitem=new Item[size];
	for(int i=0;i<top;i++){			//拷贝栈里面的数据
		pitem[i]=s.pitem[i];
	}
}

bool Stack::push(Item it){
	if(isfull())		//是否栈满 
	{
		cout <<"Stack full"<< endl;
		return false;
	}
	pitem[top++]=it;	
	return true;
}

bool Stack::pop(Item &it){
	if(isempty())		//是否栈空 
	{
		cout <<"Stack empty"<< endl;
		return false;
	}
	it=pitem[--top];
	return true;
}


Stack& Stack::operator=(Stack& st){
	if(this ==&st){			//自己拷贝自己 不能释放内存，⚠️记住
		return *this;
	}
	delete []pitem;			//删掉之前的内容
	top=st.top;
	size=st.size;
	pitem=new Item[size];
	for(int i=0;i<top;i++){
		pitem[i]=st.pitem[i];
	}
	return *this;
}

ostream& operator<<(ostream&os,Stack& st){  //重载 count
	os <<"Stack : [";
	for(int i=0;i<st.top;i++){
		os << st.pitem[i] <<" ,";
	}
	os <<"]";
	return os;
}


