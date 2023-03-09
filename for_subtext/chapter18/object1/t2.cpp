#include <iostream>
#include <utility>

using namespace std;

class Useless{
private:
	int n;
	char *pc;
	static int ct;
	void ShowObject()const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k,char ch);
	Useless(const Useless& f);
	Useless(Useless&& f);

	~Useless();
	Useless operator+(const Useless&f)const;
	Useless& operator=(Useless &&f){
		cout << "|||||||||Use move assgin" << endl;
		if(this==&f)
			return *this;
		delete []pc;
		n=f.n;
		pc=f.pc;
		f.n=0;
		f.pc=nullptr;
		return *this;

	}
	void ShowData()const;	

};

int Useless::ct=0;


Useless::Useless(){
	++ct;
	n=0;
	pc=nullptr;
	cout << "default constructor called,member of object: " << ct << endl;
	ShowObject();
}

Useless::Useless(int k):n(k){
	++ct;
	cout << "Int constructor called,number of object:" << ct << endl;
	pc=new char[n];
	ShowObject();
}

Useless::Useless(int k,char ch):n(k){
	++ct;
	cout << "Int & char constructor called,member of object:" <<ct<< endl;
	pc=new char[n];
	for(int i=0;i<n;i++){
		pc[i]=ch;
	}
	ShowObject();
}


Useless::Useless(const Useless& f):n(f.n){
	ct++;
	cout << "copy const constructor called ,the member object: " << ct<< endl;

	pc=new char[n];
	for(int i=0;i<n;i++){
		pc[i]=f.pc[i];
	}
	ShowObject();
}

//移动构造函数
Useless::Useless(Useless&& f):n(f.n){
	cout << "|||||||use right value move"<<endl;
	++ct;
	pc=f.pc;   			 //指针赋予给另外一个指针,
	f.pc=nullptr;			//清空指针 nullptr 可以再次被delete
	f.n=0;					//清空成员
}

Useless::~Useless(){
	cout << "destructor called,member left :" << --ct << endl;
	cout << "delete object:" ;
	ShowObject();
	delete []pc;
}

Useless Useless::operator+(const Useless&f)const{
	cout <<"Enter operator + "<< endl;
	Useless temp(n+f.n);
	for(int i=0;i<n;i++){
		temp.pc[i]=pc[i];
	}
	for(int i=n;i<temp.n;i++){
		temp.pc[i]=f.pc[i-n];
	}
	cout << "temp object:\n";
	cout <<"Leaving operator + " << endl;
	return temp;

}




void Useless::ShowObject()const{
	cout <<"[";
	cout << "Number of elements: " << n << endl;
	cout << "Data addr:" << (void *) pc ;
	cout<<"]\n";
}

void Useless::ShowData()const{
	if(n==0){
		cout << "(empty data)" << endl;
	}else{
		for(int i=0;i<n;i++){
			cout <<pc[i];
		}
		cout << endl;
	}
}

int main(){

	Useless t1(10,'a');
	Useless t2(20,'b');
	Useless t3;
	t3=t1+t2;

	t3.ShowData();

	// Useless one(10,'a');
	// cout << "------------------------------"<< endl;
	// one.ShowData();
	// cout << "------------------------------"<< endl;

	// Useless two(static_cast<Useless&&>(one+one));


	// Useless two2(move(one));	//把one的数据控制权交给two2
	// 							//one里面的指针为nullptr 可以再次被析构
	

	// cout << "------------------------------"<< endl;
	// one.ShowData();
	// two.ShowData();
	// two2.ShowData();
	

	
	
	// cout << "------------------------------"<< endl;




	// cout << "------------------------------"<< endl;
	// Useless one(10,'x');
	// cout << "------------------------------"<< endl;
	// Useless two(one);
	// cout << "------------------------------"<< endl;
	// Useless three(20,'o');
	// cout << "------------------------------"<< endl;
	// Useless four(one + two);
	// cout << "------------------------------"<< endl;
	// cout << "-------------show one-----------------"<< endl;
	// one.ShowData();
	// cout << "-------------show two-----------------"<< endl;
	// two.ShowData();
	// cout << "-------------show three-----------------"<< endl;
	// three.ShowData();
	// cout << "-------------show four-----------------"<< endl;
	// four.ShowData();
	// cout << "-------------code done-----------------"<< endl;




	return 0;
}















