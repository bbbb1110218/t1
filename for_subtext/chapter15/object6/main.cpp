#include <iostream>
using namespace std;


class Base{
public:
	class t1{
	public:
		int val;
		t1(int n=0):val(n){}
		void getvalue(){cout << val << endl;}
	};
	class t2{
	public:
		int val;
		t2(int n=0):val(n){}
		void getvalue(){cout << val << endl;}
	};

};



int main(){
	Base::t1 t11(20);
	cout << t11.val << endl;
	Base::t2 t22(120);
	cout << t22.val << endl;

	
	return 0;
}