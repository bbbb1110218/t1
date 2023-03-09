#include <iostream>
#include <string>
#define fuck 

int main(){
	
	using namespace std;
	string empty;		//会默认分配 固定字节,方式 string +="other string"
	string small("bit");	//的时候,内存不够
	string big("#$%^&*I(#$%^&*#$%^&*#$%^&*#%^&*&^%");

	cout << empty.capacity() << endl;
	cout << small.capacity() << endl;
	cout << big.capacity() << endl;
	cout <<"&big : " << &big <<endl;
	big +="fuckyoubitututuf";
	cout <<"after &big : " << &big <<endl;
	big.reserve(100);
	cout <<"after after &big : " << &big <<endl;
	cout << empty.capacity() << endl;
	cout << small.capacity() << endl;
	cout << big.capacity() << endl;

	string st;
	st.capacity();  //查看分配的内存 单位字节
	st.reserve(100); // 重新分配100个字节 






	return 0;
}