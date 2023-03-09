#include <iostream>
#include <string>
using namespace std;


void show_list(){}  //匹配最后一个空参数


template<class T>		//匹配最后一个参数 并且增加换行
void show_list(T t){
	cout << t << endl;	
}

/*
	show_list(x*x,"!" ,7,mr);参数会变成
	x*x , ("!" ,7,mr);		//x *x 会被打印出来，其他的呼递归给自己
	"!" ,	(7,mr); 		//"!" 会被打印出来 (7,mr)会递归给自己
	7 ，  (mr);				// 递归给自己
	mr,   ();				// mr 打印出来
					还剩下一个空参数  需要写一下空函数,啥都不用干
*/



template<typename T,typename... Args>
void show_list(T value,Args... args){
	cout << value << " , ";
	show_list(args...); 
}

int main(void){
	int n=14;
	double x=2.71;
	string mr="Mr rick";
	show_list(n,x);
	show_list(x*x,"!" ,7,mr);
	return 0;
}