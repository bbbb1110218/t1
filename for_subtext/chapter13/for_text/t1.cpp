#include <iostream>

using namespace std;
class Myclass{
private:
	int age;
public:
	explicit Myclass(int n){age=n;cout <<"[]" <<endl;}
	void show(){cout <<"age:" << age << endl;}
	void reset(int n){age=n;}
	const Myclass & fuck(const Myclass &t)const{return age > t.age ? *this:t;}
};


int main(){
	Myclass t1(5);
	Myclass t2(666);
	t1.fuck(t2);
	t1.show();
	return 0;
}