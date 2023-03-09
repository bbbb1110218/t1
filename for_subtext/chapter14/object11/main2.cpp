//非模版函数作为友元函数

#include <iostream>

using namespace std;

template<class T>
void counts();


template<class U>
void Reports(U &);


template<class V>
class HasFriend			
{
private:
	V item;
	static int ct; 
public:
	HasFriend(const V &i):item(i){ct++;}
	~HasFriend(){ct--;}

	friend void counts<V>(); //函数模版具体化
 
	friend void Reports< HasFriend<V> >(HasFriend<V> &hf); 
};


template<class V>
int HasFriend<V>::ct=0; 
						
						

template<class T>
void counts(){
	cout << "count:" << HasFriend<T>::ct ;		
}


template<class U>
void Reports(U &tp){	
	cout <<tp.item << endl;
}




int main(){

	cout <<"No object declared:";
	counts<int>();

	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared:";
	counts<int>();
	Reports(hfi1); 

	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared:";
	counts<int>();
	Reports(hfi2); 

	HasFriend<double> hfd(5.55);
	cout << "After hdf declared:";
	counts<double>();
	Reports(hfd); 

	return 0;
}


