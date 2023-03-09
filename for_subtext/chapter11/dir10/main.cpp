#include <iostream>

using namespace std;

class Number{
private:
	int real;
	int image;
public:
	Number(){real=image=0;};
	Number(int a1,int a2){real=a1,image=a2;};

	Number operator+(Number &n){
		return Number(real+n.real,image+n.image);
	}

	Number operator-(Number &n){
		return Number(real-n.real,image-n.image);
	}

	Number operator*(Number &n){
		return Number(real*n.real,image*n.image);
	}

	// Number operator~(){
	// 	return Number(real,-image);
	// }




	friend istream& operator>>(istream &is,Number &n){
		static int i=0;
		cout <<"[" << ++i <<"]"<< endl;
		cout << "Please enter the real and image :"<< endl;
		is >> n.real >> n.image;
		return is;
	}

	friend ostream& operator<<(ostream &os,Number &n){
		os << "{" << n.real << "," << n.image <<"}";
		return os;
	}


};


int main(){
	Number a(3.0,5.0);
	Number b;

	while(cin >> b){
		// cout <<"~b = " << ~b << endl;
		cout <<"a+b = " << (a+b) << endl;
		// cout <<"a-b = " << a-b << endl;
		// cout <<"a*b = " << a*b << endl;


	}


	
	return 0;
}