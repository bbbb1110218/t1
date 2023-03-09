#include <iostream>

using namespace std;


template<typename T,typename T2>
class My{
	T n;
	T2 m;
public:
	My(T&t=1,T2&t2=2){n=t;m=t2;};
	void show();

};




int main(){
	My<const char *,const char *> t;// ("hello","kitty");
	t.show();

	return 0;
}


template<typename T,typename T2>
void My::show(){
	cout <<"n = " << t << ", m = " << t2;
}