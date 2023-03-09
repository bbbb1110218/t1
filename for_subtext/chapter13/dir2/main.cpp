#include <iostream>
#include "table.h"
using std::cout;
using std::endl;
	
	
int main(){
	
	RatedPlayer s2(1000,"min","rui",false);
	TennisPlayer s3(s2); //使用派生类作为参数初始化基类对象
	s3.Name(); 



	return 0;
}
