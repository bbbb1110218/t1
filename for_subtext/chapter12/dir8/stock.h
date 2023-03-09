
#ifndef FOR_CLION_STOCK00_H
#define FOR_CLION_STOCK00_H

#include <String.h>


class Stock{
private://私有的，不能访问，只能通过public访问，数据隐藏
    String company;
    long shares;
    double  share_val;
    double total_val;

    void set_tot(){ total_val = share_val * shares;}  //私有函数,属于内联函数,分号写里面
                                                        //也可以写内联函数定义，定义写在头文件里面class外
public://公有的
    void acquire(const char * name,long n,double pr);  //类方法
    void buy(long num,double pr);
    void sell(long num,double pr);
    void update(double price);
    void show();
    std::string * show_name();

};

//set_total 内联函数的定义写在class 外面
//inline void set_tot(){
// total_val=share_val*shares;
// }



#endif //FOR_CLION_STOCK00_H
