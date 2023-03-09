//
// Created by macbookpro on 2022/11/15.
//

#include <iostream>

#include "stock.h"
#include "string.h"

int main(){
   Stock shanghai;  //shanghai是类的对象，or 类的变量
   shanghai.acquire("上海机场",1000,45.4);// 初始化 类
   shanghai.show();
   shanghai.buy(100,120);
   shanghai.show();

    shanghai.sell(2100,120);
    shanghai.show();
    std::string * name=shanghai.show_name();
    std::cout << "Name is "<< *name << std::endl;


   return 0;

}