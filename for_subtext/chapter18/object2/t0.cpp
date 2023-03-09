#include <iostream>

using namespace std;

class BS{
	int q;
	double w;
public:
	BS():q(0),w(0.0){};
	BS(int x):q(x),w(100){};
	BS(double y):q(1),w(y){};
	BS(int x,double y):q(x),w(y){}
	void Show()const{cout << q << "," << w << endl;}
};


class DR:public BS{
private:
	short j;
public:
	using BS::BS;	//使用BS自己的构造函数  要加上c++标准11 
	DR():j(-100){}
	DR(double x):BS(2*x),j(int(x)){}
	DR(int i):j(-2),BS(i,0.5*i){}
	void Show()const{cout << "j=" << j << endl;BS::Show();}
}; 

int main(){
	DR o1;			//Use DR()
	DR o2(18.81);		//USe DR(double)
	DR o3(10,1.0 );  	//USE BS(int,double) ;DR.j is random value
						//DR 里面没有与之匹配的构造函数,会调用BS 里面的构造函数 j为随机值
	o3.Show();
	return 0;
}