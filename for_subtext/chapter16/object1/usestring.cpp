#include <string>
#include <iostream>

using namespace std;


/*
	1) string(const char *) 使用这个构造函数
	string one("Lottery winner");

	2) string(size_t n,char n)
	string two(20,'A');

	3) string(const string& s)   拷贝构造函数
	string three(one);

	4) string()   空字符串
	string four;


	5) string(char *start,size_t n)  拷贝 start 前 n 个字符
	char alls[]="!@#$%^&QWERTY";
	string fine(alls,20); //不严谨  打印结果 i am eendC+ 


	6) template<class Iter>  string(iter begin,iter end);  范围不包括 end  包括 
	string six(alls+1,alls+6);


	7) string(const && str) noexcept; //可以修改  c++ 11 


	8) string(initializer_list<char>i);
	string nine{'h','e','l','l','0'};  //c++11


*/

int main(){
	//string(const char *) 使用这个构造函数
	string one("Lottery winner");
	cout << one << endl;


	//string(size_t n,char n)
	string two(20,'A');
	cout << two << endl;

	//string(const string& s)   拷贝构造函数
	string three(one);
	cout << three << endl;


	//overload operator +=
	one += "追加的";
	cout << one << endl;

	// 拷贝
	two= "Sorry,i ";
	cout << two << endl;


	two[0]='B';
	cout << two << endl;
	
	// string()   空字符串
	string four;
	four = two + three;		//operator + =  两个运算符重载过了
	cout << four << endl;

	//string(char *start,size_t n)  拷贝 start 前 n 个字符

	char alls[]="!@#$%^&QWERTY";
	string fine(alls,20); //不严谨  打印结果 i am eendC+ 

	cout << fine <<" "  <<fine.size() <<endl;

	/* 用到了模版
	template<class Iter>
	string(iter begin,iter end);  范围不包括 end  包括 
	*/

	string six(alls+1,alls+6);
	cout << six << " " << string(&alls[2],&alls[6]) << endl;

	//拷贝构造函数 string ,start_position, size  
	//string(const string &str,string size_type   
	//				 pos=0 , size_type n =npos);

	string eight(four,3,4);
	cout << eight << endl;


	// string(const && str) noexcept; //可以修改  c++ 11 


	//string(initializer_list<char>i);

	
	string nine{'h','e','l','l','0'};  //c++11

	cout << nine << endl;

	/*

	string 输入

	string temp;

	cin >> temp;

	getline(20,)

	*/










	return 0;
}